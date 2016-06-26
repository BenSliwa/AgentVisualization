#ifndef CHANNELMODELSERVICE_H
#define CHANNELMODELSERVICE_H

#include <QObject>
#include <QDebug>

#include "channelmodel.h"

class ChannelModelService : public QObject
{
    Q_OBJECT
public:
    ChannelModelService(QObject *_parent = 0);
    static ChannelModelService* getInstance();


    ChannelModel* getChannelModel();


signals:


private:
    ChannelModel *m_channelModel;
};

#endif // CHANNELMODELSERVICE_H
