#ifndef GRAPH_H
#define GRAPH_H

#include "graph_edge.h"

using namespace std;

class Graph {
private:
    vector<GraphNode*> nodes;
    vector<GraphEdge*> edges;

public:
    Graph():nodes(0), edges(0){}

    vector<GraphNode*> getNodes() {
        return nodes;
    }

    vector<GraphEdge*> getEdges() {
        return edges;
    }

    void insertNode(GraphNode* nodo){
        nodes.push_back(nodo);
    }

    void insertEdge(GraphEdge* edge){
        edges.push_back(edge);
    }

    void removeEdge(GraphEdge* edge){
        for (int i = 0; i < edges.size(); ++i) {
            if (edges[i] == edge)
                edges.erase(edges.begin()+i);
        }
    }

};
#endif
