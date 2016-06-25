#ifndef AGENT_H
#define AGENT_H

#include <QObject>
#include <QDebug>

#include "Mobility/position.h"
#include "Mobility/orientation.h"

class Agent : public QObject
{
    Q_OBJECT
public:
    Agent(const QString &_id, QObject *_parent = 0);

    void setPosition(const Position &_position);

    QString getId();
    Position* getPosition();
    Orientation* getOrientation();

signals:
    void positionUpdated();

private:
    QString m_id;

    Position m_position;
    Orientation m_orientation;
};

#endif // AGENT_H
