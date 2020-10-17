#include <iostream>
#include <vector>
#include <queue>
#include <filesystem>

#define cimg_use_jpeg
#include "CImg.h"

#include "fibonacci_heap.h"

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

vector<vector<double> > get_vectors(string directory_name) {
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
		}
		else if (entry.is_directory()) {
			auto nested = get_vectors(entry_path);
			points.insert(points.end(), nested.begin(), nested.end());
		}
	}

	return points;
}

struct GraphEdge {
	vector<double> v1;
	vector<double> v2;
	double distance;

	bool operator<(GraphEdge const &e) const {
		return this->distance < e.distance;
	}
	bool operator>(GraphEdge const &e) const {
		return this->distance > e.distance;
	}
};

// struct CompareGraphEdge {
// 	bool operator()(GraphEdge &e1, GraphEdge &e2) {
// 		return e1.distance > e2.distance;
// 	}
// };

int main() {
	vector<vector<double> > points = get_vectors("data/faces94/female/");

	int n = points.size();
	int k = 2; // Number of clusters

	cout << "Number of points: " << n << endl;
	cout << "Number of clusters: " << n << endl;

	// priority_queue<GraphEdge, vector<GraphEdge>, CompareGraphEdge> edges;
	Fibonacci_heap<GraphEdge> edges;

	for (int i = 0; i < points.size(); i++) {
		if (i % 100 == 0) 
			cout << "iteration: " << i << endl;

		for (int j = i + 1; j < points.size(); j++) {
			GraphEdge g;

			g.v1 = points[i];
			g.v2 = points[j];
			g.distance = distance(g.v1, g.v2);

			edges.Insert(new NodoB<GraphEdge>(g));
		}
	}

	vector<GraphEdge> final_edges;

	for (int i = 0; i < n - k; i++) {
		auto e = edges.Get_Min();

		cout << e.distance << endl;

		final_edges.push_back(e);

		edges.Delete_Min();
	}
	
	return 0;
}
