#ifndef CHANNELMODEL_H
#define CHANNELMODEL_H

#include <QObject>
#include <QDebug>

#include "Mobility/position.h"

class ChannelModel : public QObject
{
    Q_OBJECT
public:
    ChannelModel(QObject *_parent = 0);

    virtual double calculateReceivedSignalStrength(const Position &_sender, const Position &_receiver) = 0;
    virtual double calculateDistance(double _PrMin_dBm) = 0;

    void setFrequency(double _f_GHz);
    void setTransmissionPower(double _Ps_mW);
    void setGamma(double _gamma);
    void setTransmissionGain(double _gain);
    void setReceiverGain(double _gain);



protected:
    double dBm2mW(double _dBm);
    double mW2dBm(double _mw);

protected:
    double m_f_GHz;
    double m_Ps_mW;
    double m_gamma;
    double m_Gs;
    double m_Gr;
    double m_c;
    double m_pi;
};

#endif // CHANNELMODEL_H
