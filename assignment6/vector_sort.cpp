#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>

#include "vector_sort.h"

using namespace std;

vector<int_vector> read_file(string file_name){

    vector<int_vector> vect;

    ifstream in_file;

    in_file.open(file_name);

    int id = 0;

    string line;

    while( getline(in_file, line) ){


        stringstream stream(line);

        int from, to;
        stream >> from >> to;

        int_vector i_v;

        i_v.from = from;
        i_v.to = to;
        i_v.id = id++;
        vect.push_back(i_v);

    }

    in_file.close();

    output_vector(vect);
    
    return vect;
}


void sort_int_vector(vector<int_vector> v){

    if (v.size() < 1) return;

    sort(v.begin(),
         v.end(), 
         [](const int_vector & left, const int_vector & right){
            return left.id > right.id;
         }
    );


}

void output_vector(vector<int_vector> v){
    for(auto element: v){
        cout << element.id << ": " << element.from  << " " << element.to << endl;
    }
}