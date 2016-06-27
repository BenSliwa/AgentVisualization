#include "appcontroller.h"
#include <QQmlContext>
#include "ChannelModel/dijkstra.h"
#include "math.h"

AppController *appControllerInstance = 0;

AppController::AppController(QObject *_parent) : QObject(_parent),
    m_sender(0),
    m_destination(0),
    m_simTime_ms(0),
    m_dMax_m(0)
{
    m_settings.init(":/Settings.ini");


    ChannelModelService *channelModelService = ChannelModelService::getInstance();


    //
    m_qml.rootContext()->setContextProperty("AppController", this);
    m_qml.rootContext()->setContextProperty("Settings", &m_settings);
    m_qml.rootContext()->setContextProperty("ChannelModelService", channelModelService);

    m_qml.load(QUrl(QStringLiteral("qrc:/main.qml")));


    m_dMax_m = channelModelService->getChannelModel()->calculateDistance(-83);


    QString csvPath = m_settings.getValue("Simulation", "csvPath").toString();
    int agents = m_settings.getValue("Simulation", "agents").toInt();

    for(int i=0; i<agents; i++)
    {
        QString agentId = QString::number(i+1);
        QString path = csvPath + "Agent" + agentId + ".txt";

        Agent *agent = new Agent(agentId, this);
        CSVMobilityDataAccess *csv = new CSVMobilityDataAccess(agent, this);
        csv->load(path);

        connect(agent, SIGNAL(positionUpdated()), this, SLOT(onAgentPositionUpdated()));

        Position *position = agent->getPosition();
        emit agentAdded(agentId, position->x, position->y, position->z);

        m_csv << csv;
        m_agents.insert(agentId, agent);
    }


    setSimTime(m_simTime_ms);
}

AppController* AppController::getInstance()
{
    if(!appControllerInstance)
        appControllerInstance = new AppController();

    return appControllerInstance;
}

void AppController::setSimTime(double _simTime_ms)
{
    m_simTime_ms = _simTime_ms;

    for(int i=0; i<m_csv.size(); i++)
        m_csv.at(i)->update(_simTime_ms);


    emit clearLinks();
    QStringList agentIds = m_agents.keys();
    QMap<Agent*, QList<Agent*>> links;
    for(int i=0; i<agentIds.size(); i++)
    {
        Agent *from = m_agents.value(agentIds.at(i));
        QList<Agent*> neighbors;

        for(int j=0; j<m_agents.size(); j++)
        {
            if(i!=j)
            {
                Agent *to = m_agents.value(agentIds.at(j));

                Position p1 = *from->getPosition();
                Position p2 = *to->getPosition();

                double distance_m = sqrt(pow(p2.x-p1.x,2) + pow(p2.y-p1.y,2) + pow(p2.z-p1.z,2));
                if(distance_m<m_dMax_m)
                {
                    neighbors << to;
                    emit addLink(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z, "L");
                }
            }
        }
        links.insert(from, neighbors);

    }


    //
    if(m_sender && m_destination)
    {
        Dijkstra dijkstra;
        QList<Agent*> path = dijkstra.getDijkstraPath(m_sender, m_destination, m_agents.values(), links);

        if(path.size()>1)
        {
            for(int i=1; i<path.size(); i++)
            {
                Position p1 = *path.at(i-1)->getPosition();
                Position p2 = *path.at(i)->getPosition();
                emit addLink(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z, "C");
            }
        }
    }





    emit updateLinks();

}

void AppController::handleAgentLeftClick(const QString &_id)
{
    m_sender = m_agents.value(_id);
}

void AppController::handleAgentRightClick(const QString &_id)
{
    m_destination = m_agents.value(_id);

    setSimTime(m_simTime_ms);
}

void AppController::handleGammaChange(double _gamma)
{
    ChannelModelService *channelModelService = ChannelModelService::getInstance();
    ChannelModel *channelModel = channelModelService->getChannelModel();

    channelModel->setGamma(_gamma);
    m_dMax_m = channelModelService->getChannelModel()->calculateDistance(-83);

    setSimTime(m_simTime_ms);
}

void AppController::onAgentPositionUpdated()
{
    Agent *agent = qobject_cast<Agent*>(QObject::sender());
    if(agent)
    {
        Position *position = agent->getPosition();
        emit agentPositionUpdated(agent->getId(), position->x, position->y, position->z);
    }
}
