#include "dijkstra.h"

Dijkstra::Dijkstra(QObject *_parent) : QObject(_parent)
{
    m_inf = std::numeric_limits<int>::max();
}

QList<Agent*> Dijkstra::getDijkstraPath(Agent *_startNode, Agent *_targetNode, const QList<Agent*> &_agents, const QMap<Agent*,QList<Agent*>> &_links)
{
    m_agents = _agents;
    m_links = _links;

    QList<Agent*> path;

    // setup the class member variables
    m_distances.clear();
    m_nodes.clear();
    m_predecessors.clear();

    m_nodes = _agents;

    // algorithm
    init(_startNode);

    while(m_nodes.size()>0)
    {
        Agent *u = getNearestNode();
        if(!u)
            return path;

        // remove u from node set
        int index = m_nodes.indexOf(u);
        m_nodes.removeAt(index);

        if(u==_targetNode)
        {
            path = getShortestPath(_targetNode);
            return path;
        }


        // check all node neighbors
        QList<Agent*> neighbors = m_links.value(u);
        for(int i=0; i<neighbors.size(); i++)
        {
            Agent *neighbor = neighbors.at(i);
            int neighborIndex = m_nodes.indexOf(neighbor);
            if(neighborIndex>-1)    // neighbor is in the node set
                updateDistance(u, neighbor);


        }

    }

    path = getShortestPath(_targetNode);
    return path;
}


void Dijkstra::init(Agent *_startNode)
{
    for(int i=0; i<m_nodes.size(); i++)
    {
        Agent *node = m_nodes.at(i);
        m_distances.insert(node, m_inf);
        m_predecessors.insert(node, 0);
    }
    m_distances.insert(_startNode, 0);
}

void Dijkstra::updateDistance(Agent *_nodeU, Agent *_nodeV)
{
    double newDistance = getDistanceById(_nodeU) + getDistanceBetweenNodes(_nodeU, _nodeV);
    if(newDistance<getDistanceById(_nodeV))
    {
        m_distances.insert(_nodeV, newDistance);
        m_predecessors.insert(_nodeV, _nodeU);
    }
}

QList<Agent*> Dijkstra::getShortestPath(Agent *_targetNode)
{
    QList<Agent*> path;
    path.append(_targetNode);

    Agent *u = _targetNode;
    while(getPredecessorById(u)!=0)
    {
        u = getPredecessorById(u);
        path.push_front(u);
    }
    return path;
}

double Dijkstra::getDistanceBetweenNodes(Agent *_from, Agent *_to)
{
    Position *p1 = _from->getPosition();
    Position *p2 = _to->getPosition();

    double distance = sqrt(pow(p2->x-p1->x,2) + pow(p2->y-p1->y,2) + pow(p2->z-p1->z,2));

    return distance;
}

double Dijkstra::getDistanceById(Agent *_agent)
{
    return m_distances.value(_agent);
}

Agent* Dijkstra::getPredecessorById(Agent *_agent)
{
    return m_predecessors.value(_agent);
}

Agent* Dijkstra::getNearestNode()
{
    double nearestDistance = m_inf;
    Agent *nearestNode = 0;

    for(int i=0; i<m_nodes.size(); i++)
    {
        Agent *currentNode = m_nodes.at(i);
        double currentDistance = getDistanceById(currentNode);

        if(currentDistance<nearestDistance)
        {
            nearestDistance = currentDistance;
            nearestNode = currentNode;
        }
    }

    return nearestNode;
}
