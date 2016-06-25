#ifndef MOBILITYDATA_H
#define MOBILITYDATA_H

#include <QObject>
#include <QDebug>
#include <QString>

#include "position.h"

class MobilityData
{
public:
    MobilityData();

    static MobilityData fromString(const QString &_data);

public:
    double timestamp_ms;
    Position position;

};

#endif // MOBILITYDATA_H
