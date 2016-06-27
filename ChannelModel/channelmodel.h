#ifndef CHANNELMODEL_H
#define CHANNELMODEL_H

#include <QObject>
#include <QDebug>

class ChannelModel : public QObject
{
    Q_OBJECT
public:
    ChannelModel(QObject *_parent = 0);

    virtual double calculateReceivedSignalStrength(double _distance_m) = 0;
    virtual double calculateDistance(double _PrMin_dBm) = 0;

    void setGamma(double _gamma);


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
