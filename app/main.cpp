#include <iostream>
#include <vector>
#include <filesystem>

#define cimg_use_jpeg
#include "CImg.h"

#include "fibonacci_heap.h"
#include "graph/graph.h"

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

	return total;
}

vector<vector<double> > get_vectors(string directory_name, &vector<string> paths) {
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
			auto nested = get_vectors(entry_path);
			points.insert(points.end(), nested.begin(), nested.end());
		}
	}

	return points;
}

// struct GraphEdge {
// 	vector<double> v1;
// 	vector<double> v2;
// 	double distance;
// 
// 	bool operator<(GraphEdge const &e) const {
// 		return this->distance < e.distance;
// 	}
// 	bool operator>(GraphEdge const &e) const {
// 		return this->distance > e.distance;
// 	}
// };

int main() {
    vector<string> paths;
	vector<vector<double> > points = get_vectors("data/faces94/female/", paths);

	int n = points.size();
	int k = 2; // Number of clusters

	cout << "Number of points: " << n << endl;
	cout << "Number of clusters: " << n << endl;

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
