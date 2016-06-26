#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <QObject>
#include <QDebug>

#include "Agent/agent.h"


class Dijkstra : public QObject
{
    Q_OBJECT
public:
    Dijkstra(QObject *_parent = 0);

    QList<Agent*> getDijkstraPath(Agent *_startNode, Agent *_targetNode, const QList<Agent*> &_agents, const QMap<Agent*,QList<Agent*>> &_links );

private:
    // Algorithm
    void init(Agent *_startNode);
    void updateDistance(Agent *_nodeU, Agent *_nodeV);
    QList<Agent*> getShortestPath(Agent *_targetNode);

    // Helper methods
    double getDistanceBetweenNodes(Agent *_from, Agent *_to);
    double getDistanceById(Agent *_agent);
    Agent* getPredecessorById(Agent *_agent);
    Agent* getNearestNode();




private:
    QList<Agent*> m_agents;
    QMap<Agent*,QList<Agent*>> m_links;

    QList<Agent*> m_nodes;
    QHash<Agent*, Agent*> m_predecessors;
    QHash<Agent*, double> m_distances;

    int m_inf;
};

#endif // DIJKSTRA_H
