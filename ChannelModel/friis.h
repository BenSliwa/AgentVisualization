#ifndef FRIIS_H
#define FRIIS_H

#include "channelmodel.h"

class Friis : public ChannelModel
{
    Q_OBJECT
public:
    Friis(QObject *_parent = 0);

    double calculateReceivedSignalStrength(const Position &_sender, const Position &_receiver);
    double calculateDistance(double _PrMin_dBm);
};

#endif // FRIIS_H
