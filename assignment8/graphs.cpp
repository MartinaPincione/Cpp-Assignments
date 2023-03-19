#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>

#include "graphs.h"

using namespace std;

vector<vector<int>> readFileVertices(string fileName){

    //open the file
    ifstream f(fileName);

    int nodes, vertices;

    f >> nodes >> vertices;

    if (nodes == 0|| vertices == 0) return {};

    vector<vector<int>> adjacency(nodes);

    /*  i.e. 3, 3

        [0]
        [1]
        [2]

        1 2
        0 1
        2 0

        [0] [1] [2]
        [1] [0] [2]
        [2] [0] [1]

        packaged as [[1, 2], [0, 2], [0, 1]] 

    */

    for(int i = 0; i < vertices; i++){
        int v1, v2;
        f >> v1 >> v2;
        adjacency[v1].push_back(v2);
        adjacency[v2].push_back(v1);



    }

    f.close();
    return adjacency;

}

void printVector(vector<vector<int>> v){
    for(int i = 0; i < v.size(); i++){
        for(int j = 0 ; j < v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

bool verifyEqual(vector<vector<int>> v, vector<vector<int>> e){
    if (v.size() != e.size()) return false;
    for(int i = 0; i < v.size(); i++){
        if(v[i].size() != e[i].size()) return false;
        for(int j = 0; j < v[i].size(); j++){
            if (v[i][j] != e[i][j]) return false;
        }
    }
    return true;
}