#ifndef EDGE_H
#define EDGE_H

#include "graph_node.h"

class GraphEdge {

public:
    GraphNode* nodes[2]{};

    GraphEdge(GraphNode* nodo1, GraphNode* nodo2, double value):data(value){
        nodes[0]=nodo1;
        nodes[1]=nodo2;
    };
    GraphEdge(const GraphEdge &edge){
        nodes[0]=edge.nodes[0];
        nodes[1]=edge.nodes[1];
		data=edge.data;
    };

    double getData() const{
        return data;
    }

    GraphNode* getNode1() {
        return nodes[0];
    }

    GraphNode* getNode2() {
        return nodes[1];
    }

    bool operator<(GraphEdge const &e) const {
        return this->data < e.data;
    }
    bool operator>(GraphEdge const &e) const {
        return this->data > e.data;
    }


private:
    double data;
};

#endif
