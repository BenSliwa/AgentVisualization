#ifndef CSVMOBILITYDATAACCESS_H
#define CSVMOBILITYDATAACCESS_H

#include <QObject>
#include <QDebug>

#include "Agent/agent.h"
#include "mobilitydata.h"

class CSVMobilityDataAccess : public QObject
{
public:
    CSVMobilityDataAccess(Agent *_agent, QObject *_parent = 0);

    void load(const QString &_path);

    void update(double _time_ms);

private:
    Agent *p_agent;
    QStringList m_rawData;
};

#endif // CSVMOBILITYDATAACCESS_H
