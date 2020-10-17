#ifndef GRAPH_H
#define GRAPH_H

#include "graph_edge.h"

using namespace std;

class Graph {
private:
    vector<Node*> nodes;
	vector<Edge*> edges;

public:
	Graph():nodes(0), edges(0){}

	vector<Node*> getNodes() {
	    return nodes;
	}

    vector<Edge*> getEdges() {
        return edges;
    }

	void insertNode(Node* nodo){
	    nodes.push_back(nodo);
	}

	void insertEdge(Edge* edge){
	    edges.push_back(edge);
	}

	void removeEdge(Edge* edge){
        for (int i = 0; i < edges.size(); ++i) {
            if (edges[i] == edge)
                edges.erase(edges.begin()+i);
        }
	}

};
#endif
