#include "udp.h"

Udp::Udp(const QMap<QString, QVariant> &_settings, QObject *_parent) : QObject(_parent)
{
    connect(&m_socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));

    int port = _settings.value("port").toInt();


}

void Udp::sendData(const QByteArray &_data, const QString &_remoteAddress, int _remotePort)
{
    m_socket.writeDatagram(_data, QHostAddress(_remoteAddress), _remotePort);
}

void Udp::onReadyRead()
{
    while(m_socket.hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(m_socket.pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        m_socket.readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);


    }
}
