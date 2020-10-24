#include <iostream>
#include <vector>
#include <filesystem>
#include <cmath>

#define cimg_use_jpeg
#include "CImg.h"

#include "fibonacci_heap.h"
#include "graph/graph.h"
#include "disjoint_set.hpp"

using namespace cimg_library;
using namespace std;

vector<double> vectorize(CImg<double> &img) {
	CImg<double> haar = img.haar(false, 3);
	CImg<double> crop = haar.crop(0, 0, 27, 27);
	
	vector<double> result;

	cimg_forXY(crop, x, y) { 
		result.push_back((crop(x, y, 0) + crop(x, y, 1) + crop(x, y, 2)) / 3);
	}

	return result;
}

double distance(vector<double> v1, vector<double> v2) {
	double total = 0;

	for (int i = 0; i < v1.size(); i++) {
		total += (v1[i] - v2[i]) * (v1[i] - v2[i]);
	}

	return sqrt(total);
}

int k;

vector<vector<double> > get_vectors(string directory_name, vector<string> &paths) {
	vector<vector<double> > points;

	for (const auto& entry : filesystem::directory_iterator(directory_name)) {
		string entry_path = directory_name;
		entry_path.append("/");
		entry_path.append(entry.path().filename().string());

		if (entry.is_regular_file() && entry_path.compare(entry_path.length() - 3, 3, "jpg") == 0) {
			CImg<double> A(entry_path.c_str());
			A.resize(384, 288);
			vector<double> vA = vectorize(A);
			points.push_back(vA);
			paths.push_back(entry_path);
		}
		else if (entry.is_directory()) {
			k++;
			auto nested = get_vectors(entry_path, paths);
			points.insert(points.end(), nested.begin(), nested.end());
		}
	}

	return points;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		cout << "Usage:./bin/graph <directory>" << endl;
		return 1;
	}

	string path(argv[1]);
		
	k = 0; // Number of clusters

    vector<string> paths;
	vector<vector<double> > points = get_vectors(path, paths);

	int n = points.size();

	Fibonacci_heap<GraphEdge> fh;
    Graph g, g_final;

    for (int i = 0; i < n; ++i) {
        auto nodo = new GraphNode(paths[i], points[i]);
        g.insertNode(nodo);
        g_final.insertNode(nodo);
    }
    auto nodos = g.getNodes();

	eda::disjoint_set::DisjointSet<GraphNode*> ds;

    for (int i = 0; i < nodos.size(); i++) {
        for (int j = i+1; j < nodos.size(); ++j) {
            double d = distance(nodos[i]->getVector(), nodos[j]->getVector());
            auto edge = new GraphEdge(nodos[i], nodos[j], log(d));
            g.insertEdge(edge);
            fh.Insert(new NodoB<GraphEdge>(*edge));
        }

		ds.insert(nodos[i]);
    }

    vector<GraphEdge> final_edges;

	cout << "graph {" << endl;

    for (int i = 0; i < n - k && fh.getM_size() > 0; ) {
        auto e = fh.Get_Min();
        fh.Delete_Min();

		if (ds.same_set(e.getNode1(), e.getNode2())) continue;
		ds.combine(e.getNode1(), e.getNode2());

		cout << (long long) e.getNode1() << " -- " << (long long) e.getNode2() << " [len=" << (long long) e.getData() << "];" << endl;

        final_edges.push_back(e);
		i++;
    }

	cout << "}" << endl;

	// cout << "graph {" << endl;

	// for (auto e : final_edges) {
	// 	cout << (long long) e->getNode1() << " -- " << (long long) e->getNode2() << " [len=" << (long long) sqrt(e->getData()) << "];" << endl;
	// }

	// cout << "}" << endl;

    return 0;
}
