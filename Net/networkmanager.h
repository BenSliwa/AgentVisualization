#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <QDebug>
#include <QMap>

#include "udp.h"
#include "protocol.h"
#include "appcontroller.h"

class NetworkManager : public QObject
{
    Q_OBJECT
public:
    NetworkManager(QObject *_parent = 0);
    static NetworkManager* getInstance();

    void init();


private:
    Protocol *m_protocol;

};

#endif // NETWORKMANAGER_H
