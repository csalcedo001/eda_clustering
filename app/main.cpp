#include <iostream>
#include <vector>

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

int main() {
	CImg<double> A("data/example1.jpg");
	CImg<double> B("data/example2.jpg");
	CImg<double> C("data/example3.jpg");
	
	A.resize(384, 288);
	B.resize(384, 288);
	C.resize(384, 288);
	
	vector<double> vA = vectorize(A);
	vector<double> vB = vectorize(B);
	vector<double> vC = vectorize(C);

	cout << "A - B distance: " << distance(vA, vB) << endl;
	cout << "A - C distance: " << distance(vA, vC) << endl;
	cout << "B - C distance: " << distance(vB, vC) << endl;
	
	return 0;
}
