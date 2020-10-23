#include <iostream>
#include <vector>

#include "fibonacci_heap.hpp"
#include "graph/graph.h"

using namespace std;


double distance(vector<double> v1, vector<double> v2) {
    double total = 0;

    for (int i = 0; i < v1.size(); i++) {
        total += (v1[i] - v2[i]) * (v1[i] - v2[i]);
    }

    return total;
}

int main() {
    vector<string> paths = {"cara1.jpg","cara2.jpg","cara3.jpg","cara4.jpg"};
    vector<vector<double> > points = {{1.1,2.2,3.3,4.4},{1.2,2.3,3.4,4.5},{1.6,2.7,3.8,4.9},{1.7,2.8,3.9,5.0}};


    int n = points.size();
    int k = 2; // Number of clusters

    cout << "Number of points: " << n << endl;
    cout << "Number of clusters: " << k << endl;

    eda::fibonacci_heap::FibonacciHeap<GraphEdge*> fh;
    Graph g, g_final;

    for (int i = 0; i < n; ++i) {
        auto nodo = new GraphNode(paths[i], points[i]);
        g.insertNode(nodo);
        g_final.insertNode(nodo);
    }
    auto nodos = g.getNodes();
    for (int i = 0; i < nodos.size(); i++) {
        for (int j = i+1; j < nodos.size(); ++j) {
            double d = distance(nodos[i]->getVector(), nodos[j]->getVector());
            auto edge = new GraphEdge(nodos[i], nodos[j], d);
            g.insertEdge(edge);
            fh.insert(edge);
        }
    }

    vector<GraphEdge*> final_edges;

    for (int i = 0; i < n - k; i++) {
        auto e = fh.get_min();

        cout << e->getData() << endl;

        final_edges.push_back(e);

        fh.delete_min();
    }

    return 0;
}
