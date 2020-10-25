#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
using namespace std;

class GraphNode {
public:
    GraphNode(const string& path, vector<double> data){
        this->path = path;
        this->data = data;
    }

    string getPath(){
        return path;
    }

    vector<double> getVector(){
        return data;
    }


private:
    string path;
    vector<double> data;
};

#endif
