#include "csvmobilitydataaccess.h"
#include "filehandler.h"

CSVMobilityDataAccess::CSVMobilityDataAccess(Agent *_agent, QObject *_parent) : QObject(_parent),
    p_agent(_agent)
{

}

void CSVMobilityDataAccess::load(const QString &_path)
{
    m_rawData = FileHandler::readLines(_path);

    if(m_rawData.size()>1)
    {
        MobilityData currentData = MobilityData::fromString(m_rawData.at(0));
        p_agent->setPosition(currentData.position);
    }
}


void CSVMobilityDataAccess::update(double _time_ms)
{
    double updateInterval = 250;
    int iteration = (_time_ms/updateInterval);

    if(iteration>m_rawData.size()-1)
        iteration = m_rawData.size() - 1;

    if(iteration>-1)
    {
        MobilityData currentData = MobilityData::fromString(m_rawData.at(iteration));
        p_agent->setPosition(currentData.position);
    }
}
