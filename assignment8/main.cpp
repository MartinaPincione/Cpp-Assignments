#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>

using namespace std;


ostream &operator<<(ostream &os, const vector<int> &input){
    for (auto const &i: input) {
        os << i << " ";
    }
    return os;
}

int main(){

    vector<vector<int>> nodes;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);

    nodes.push_back(v);


    cout << nodes[0] << endl;
}