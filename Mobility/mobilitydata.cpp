#include "mobilitydata.h"

MobilityData::MobilityData()
{

}

MobilityData MobilityData::fromString(const QString &_data)
{
    MobilityData data;

    QStringList rawData = _data.split(",");
    if(rawData.size()>4)
    {
        data.timestamp_ms = rawData.at(0).toDouble();
        data.position = Position(rawData.at(1).toDouble(), rawData.at(2).toDouble(), rawData.at(3).toDouble());
    }

    return data;
}
