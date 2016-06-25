#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include <QObject>
#include <QDebug>
#include <QQmlApplicationEngine>

#include "inisettings.h"
#include "Mobility/csvmobilitydataaccess.h"
#include "Agent/agent.h"

class AppController : public QObject
{
    Q_OBJECT
public:
    AppController(QObject *_parent = 0);
    static AppController* getInstance();

    Q_INVOKABLE void setSimTime(double _simTime_ms);

private slots:
    void onAgentPositionUpdated();

signals:
    void agentAdded(const QString &_id, double _x, double _y, double _z);
    void agentPositionUpdated(const QString &_id, double _x, double _y, double _z);

private:
    QQmlApplicationEngine m_qml;

    IniSettings m_settings;

    QList<CSVMobilityDataAccess*> m_csv;
};

#endif // APPCONTROLLER_H
