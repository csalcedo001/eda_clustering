#include <iostream>
#include <vector>

#define cimg_use_jpeg
#include "CImg.h"

using namespace cimg_library;
using namespace std;

vector<float> vectorize(CImg<float> &img)
{
	vector<float> result;

	cimg_forXY(img, x, y) { 
		result.push_back((img(x, y, 0) + img(x, y, 1) +  img(x, y, 2)) / 3);
	}

	return result;
}


int main() {
	CImg<float> A("data/example.jpg");
	
	A.resize(384, 288);
	
	CImg<float> B = A.haar(false, 3);
	CImg<float> C = B.crop(0, 0, 27, 27);
	
	vector v = vectorize(C);

	cout << "Vector size: " << v.size() << endl;
	
	A.display();
	
	return 0;
}


