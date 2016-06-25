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
    int iteration = (_time_ms/updateInterval)-1;

    if(iteration<m_rawData.size()-1 && iteration>-1)
    {
        MobilityData currentData = MobilityData::fromString(m_rawData.at(iteration));
        MobilityData nextData = MobilityData::fromString(m_rawData.at(iteration+1));

        if(currentData.timestamp_ms<=_time_ms && nextData.timestamp_ms>_time_ms)
            p_agent->setPosition(currentData.position);
    }
}

/*
void CSVMobilityDataAccess::update(double _time_ms)
{
    int i = 0;
    bool done = false;
    while(!done)
    {
        if(i<m_rawData.size()-1)
        {
            MobilityData currentData = MobilityData::fromString(m_rawData.at(i));
            MobilityData nextData = MobilityData::fromString(m_rawData.at(i+1));

            if(currentData.timestamp_ms<=_time_ms && nextData.timestamp_ms>_time_ms)
            {
                m_currentData = MobilityData::fromString(m_rawData.at(i));
                m_nextData = MobilityData::fromString(m_rawData.at(i+1));

                p_agent->setPosition(m_currentData.position);
                done = true;
            }

        }
        else
            done = true;

        i++;
    }
}
*/
