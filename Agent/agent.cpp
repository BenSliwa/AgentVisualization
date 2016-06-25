#include "agent.h"

Agent::Agent(const QString &_id, QObject *_parent) : QObject(_parent),
    m_id(_id)
{

}

void Agent::setPosition(const Position &_position)
{
    m_position.x = _position.x;
    m_position.y = _position.y;
    m_position.z = _position.z;

    emit positionUpdated();
}

QString Agent::getId()
{
    return m_id;
}

Position* Agent::getPosition()
{
    return &m_position;
}

Orientation* Agent::getOrientation()
{
    return &m_orientation;
}
