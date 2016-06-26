#ifndef UDP_H
#define UDP_H

#include <QObject>
#include <QDebug>
#include <QUdpSocket>
#include <QMap>

class Udp : public QObject
{
    Q_OBJECT
public:
    Udp(const QMap<QString, QVariant> &_settings, QObject *_parent = 0);

    void sendData(const QByteArray &_data, const QString &_remoteAddress, int _remotePort);

private slots:
    void onReadyRead();


private:
    QUdpSocket m_socket;
};

#endif // UDP_H
