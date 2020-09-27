/*
 * Customer defined delete function for shared_ptr.
 *
 * Compilation: g++ -std=c++11 deleter.cpp -o deleter
 *
 */
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

void deleter(vector<int> *p) {
    delete[] p;
    cout << "deleter called" << endl;
}

int main() {

    //shared_ptr<vector<int> > p(new vector<int>[12], deleter);

    shared_ptr<vector<int> > p(new vector<int>[12], [](vector<int> *x){
        delete[] x;
        cout << "deleter called" << endl;            
    });
    return 0;
}
