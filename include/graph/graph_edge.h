#ifndef EDGE_H
#define EDGE_H

#include "graph_node.h"

class Edge {

  public:
    Node* nodes[2]{};

    Edge(Node* nodo1, Node* nodo2, double value):data(value){
      nodes[0]=nodo1;
      nodes[1]=nodo2;
    };

    double getData() const{
      return data;
    }

    Node* getNode1() {
        return nodes[0];
    }

    Node* getNode2() {
        return nodes[1];
    }


  private:
    double data;
};

#endif
