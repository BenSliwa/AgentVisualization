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

void ChannelModel::setFrequency(double _f_GHz)
{
    m_f_GHz = _f_GHz;
}

void ChannelModel::setTransmissionPower(double _Ps_mW)
{
    m_Ps_mW = _Ps_mW;
}

void ChannelModel::setGamma(double _gamma)
{
    m_gamma = _gamma;
}

void ChannelModel::setTransmissionGain(double _gain)
{
    m_Gs = _gain;
}

void ChannelModel::setReceiverGain(double _gain)
{
    m_Gr = _gain;
}
