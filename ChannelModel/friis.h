#ifndef FRIIS_H
#define FRIIS_H

#include "channelmodel.h"

class Friis : public ChannelModel
{
    Q_OBJECT
public:
    Friis(QObject *_parent = 0);

    double calculateReceivedSignalStrength(double _distance_m);
};

#endif // FRIIS_H