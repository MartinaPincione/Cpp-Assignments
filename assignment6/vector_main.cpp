#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

#include "vector_sort.h"

using namespace std;


int main(){

    ifstream in_file;
    in_file.open("vectors_2D.txt");

    vector<int_vector> vect;

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

        cout << endl;
    }

    cout << vect.size() << endl;

    cout << "______________________________________________" << endl << endl;
    for(auto v: vect){
        cout << v.id << ": " << v.from  << " " << v.to << endl;
    }

    sort(vect.begin(),
         vect.end(), 
         [](const int_vector & left, const int_vector & right){
            return left.id > right.id;
         }
    );

    cout << "Sorted" << endl;
    cout << "______________________________________________" << endl << endl;
    for(auto v: vect){
        cout << v.id << ": " << v.from  << " " << v.to << endl;
    }
    
    in_file.close();

    return 0;
}