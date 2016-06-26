#include "networkmanager.h"

NetworkManager *networkManagerInstance = 0;

NetworkManager::NetworkManager(QObject *_parent) : QObject(_parent)
{

}

void NetworkManager::init()
{

}

NetworkManager* NetworkManager::getInstance()
{
    if(!networkManagerInstance)
        networkManagerInstance = new NetworkManager();

    return networkManagerInstance;
}
