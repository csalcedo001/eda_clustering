#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
using namespace std;

class Node {
  public:
    Node(const string& path, vector<double> data){
        this->path = path;
        this->data = std::move(data);
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
