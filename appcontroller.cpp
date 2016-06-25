#include "appcontroller.h"
#include <QQmlContext>


AppController *appControllerInstance = 0;

AppController::AppController(QObject *_parent) : QObject(_parent)
{
    m_settings.init(":/Settings.ini");





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
