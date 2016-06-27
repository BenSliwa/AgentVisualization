#ifndef TWORAY_H
#define TWORAY_H

#include "channelmodel.h"

class TwoRay : public ChannelModel
{
    Q_OBJECT
public:
    TwoRay(QObject *_parent = 0);

    double calculateReceivedSignalStrength(Position &_sender, const Position &_receiver);
    double calculateDistance(double _pRMin_dBm);
};

#endif // TWORAY_H
