#include "tworay.h"

TwoRay::TwoRay(QObject *_parent) : ChannelModel(_parent)
{

}
double TwoRay::calculateReceivedSignalStrength(Position &_sender, const Position &_receiver)
{
    return 0;
}

double TwoRay::calculateDistance(double _pRMin_dBm)
{
    return 0;
}
