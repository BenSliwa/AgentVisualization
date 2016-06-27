#include "friis.h"

Friis::Friis(QObject *_parent) : ChannelModel(_parent)
{
    m_f_GHz = 2.4 * pow(10, 9);
    m_Ps_mW = 100;
    m_gamma = 2.65;
    m_Gs = 1;
    m_Gr = 1;
}

double Friis::calculateReceivedSignalStrength(const Position &_sender, const Position &_receiver)
{
    double distance_m = sqrt(pow(_receiver.x-_sender.x,2) + pow(_receiver.y-_sender.y,2) + pow(_receiver.z-_sender.z,2));

    double pR_mW = m_Ps_mW * m_Gs * m_Gr * pow(m_c/(4*m_pi*m_f_GHz), 2) * 1/pow(distance_m, m_gamma);
    return mW2dBm(pR_mW);
}

double Friis::calculateDistance(double _pRMin_dBm)
{
    double pRmin_mW = dBm2mW(_pRMin_dBm);
    double distance_m = pow(m_Ps_mW * m_Gs * m_Gr / pRmin_mW * pow(m_c/(4*m_pi*m_f_GHz), 2), 1/m_gamma);

    return distance_m;
}
