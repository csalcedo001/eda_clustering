#include <iostream>
#include <vector>
#include <queue>

#define cimg_use_jpeg
#include "CImg.h"

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

vector<vector<double> > get_vectors() {
	vector<vector<double> > points;

	CImg<double> A("data/example1.jpg");
	A.resize(384, 288);
	vector<double> vA = vectorize(A);
	points.push_back(vA);
	
	CImg<double> B("data/example2.jpg");
	B.resize(384, 288);
	vector<double> vB = vectorize(B);
	points.push_back(vB);
	
	CImg<double> C("data/example3.jpg");
	C.resize(384, 288);
	vector<double> vC = vectorize(C);
	points.push_back(vC);

	return points;
}

struct GraphEdge {
	vector<double> v1;
	vector<double> v2;
	double distance;
};

struct CompareGraphEdge {
	bool operator()(GraphEdge &e1, GraphEdge &e2) {
		return e1.distance < e2.distance;
	}
};

int main() {
	vector<vector<double> > points = get_vectors();

	int n = points.size();
	int k = 2; // Number of clusters

	priority_queue<GraphEdge, vector<GraphEdge>, CompareGraphEdge> edges;

	for (int i = 0; i < points.size(); i++) {
		for (int j = i + 1; j < points.size(); j++) {
			GraphEdge g;

			g.v1 = points[i];
			g.v2 = points[j];
			g.distance = distance(g.v1, g.v2);

			edges.push(g);
		}
	}

	while (edges.size() > n - k) edges.pop();

	while (edges.size() > 0) {
		auto e = edges.top();

		cout << e.distance << endl;

		edges.pop();
	}
	
	return 0;
}
