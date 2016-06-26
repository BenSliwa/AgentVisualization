#include "channelmodel.h"
#include "math.h"

ChannelModel::ChannelModel(QObject *_parent) : QObject(_parent)
{
    m_c = 3 * pow(10, 8);
    m_pi = 3.14159265359;
}

double ChannelModel::dBm2mW(double _dBm)
{
    return pow(10, (_dBm/10));
}

double ChannelModel::mW2dBm(double _mw)
{
    return 10 * log10(_mw);
}
