#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include <QObject>
#include <QDebug>
#include <QQmlApplicationEngine>

#include "inisettings.h"
#include "Mobility/csvmobilitydataaccess.h"
#include "Agent/agent.h"
#include "ChannelModel/channelmodelservice.h"

class AppController : public QObject
{
    Q_OBJECT
public:
    AppController(QObject *_parent = 0);
    static AppController* getInstance();

    Q_INVOKABLE void setSimTime(double _simTime_ms);

    Q_INVOKABLE void handleAgentLeftClick(const QString &_id);
    Q_INVOKABLE void handleAgentRightClick(const QString &_id);

private slots:
    void onAgentPositionUpdated();

signals:
    void agentAdded(const QString &_id, double _x, double _y, double _z);
    void agentPositionUpdated(const QString &_id, double _x, double _y, double _z);

    void clearLinks();
    void addLink(double _x1, double _y1, double _z1, double _x2, double _y2, double _z2, const QString &_type);
    void updateLinks();

private:
    QQmlApplicationEngine m_qml;

    IniSettings m_settings;

    QList<CSVMobilityDataAccess*> m_csv;
    QMap<QString, Agent*> m_agents;


    Agent* m_sender;
    Agent* m_destination;


    double m_simTime_ms;

};

#endif // APPCONTROLLER_H
