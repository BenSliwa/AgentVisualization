#include "appcontroller.h"
#include <QQmlContext>
#include "math.h"

AppController *appControllerInstance = 0;

AppController::AppController(QObject *_parent) : QObject(_parent)
{
    m_settings.init(":/Settings.ini");


    ChannelModelService *channelModelService = ChannelModelService::getInstance();


    //
    m_qml.rootContext()->setContextProperty("AppController", this);
    m_qml.rootContext()->setContextProperty("Settings", &m_settings);

    m_qml.load(QUrl(QStringLiteral("qrc:/main.qml")));



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
        m_agents << agent;
    }


}

AppController* AppController::getInstance()
{
    if(!appControllerInstance)
        appControllerInstance = new AppController();

    return appControllerInstance;
}

void AppController::setSimTime(double _simTime_ms)
{
    for(int i=0; i<m_csv.size(); i++)
        m_csv.at(i)->update(_simTime_ms);


    ChannelModel *channelModel = ChannelModelService::getInstance()->getChannelModel();
    emit clearLinks();

    double maxDistance_m = 200;
    for(int i=0; i<m_agents.size(); i++)
    {
        Agent *from = m_agents.at(i);
        for(int j=0; j<m_agents.size(); j++)
        {
            if(i!=j)
            {
                Agent *to = m_agents.at(j);

                Position p1 = *from->getPosition();
                Position p2 = *to->getPosition();

                double distance_m = sqrt(pow(p2.x-p1.x,2) + pow(p2.y-p1.y,2) + pow(p2.z-p1.z,2));
                if(distance_m<maxDistance_m)
                    emit addLink(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);


            }
        }
    }

    emit updateLinks();

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
