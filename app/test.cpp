#include <iostream>
#include "fibonacci_heap.h"

using namespace std;

int main() {
    Fibonacci_heap<int>* bh = new Fibonacci_heap<int>();

    for(int i = 1; i<= 10; i++) {
        bh->Insert(new NodoB<int>(i));
    }
    cout<<"\n";
    bh->Delete_Min();
    bh->print();
    //bh->write();
    return 0;
}