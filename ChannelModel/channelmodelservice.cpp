#include "channelmodelservice.h"
#include "friis.h"

ChannelModelService *channelModelServiceInstance = 0;

ChannelModelService::ChannelModelService(QObject *_parent) : QObject(_parent),
    m_channelModel(0)
{
    m_channelModel = new Friis(this);
}

ChannelModelService* ChannelModelService::getInstance()
{
    if(!channelModelServiceInstance)
        channelModelServiceInstance = new ChannelModelService();

    return channelModelServiceInstance;
}

ChannelModel* ChannelModelService::getChannelModel()
{
    return m_channelModel;
}
