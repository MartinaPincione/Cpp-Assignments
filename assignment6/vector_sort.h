#ifndef __VECTOR_SORT_H_
#define  __VECTOR_SORT_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;


struct int_vector {
 int id;
 int from;
 int to;

 int_vector(const int_vector & i_v) : id(i_v.id), from(i_v.from), to(i_v.to) {}; // copy constructor
 
 int_vector() : id(-1), from(0), to(0) {}; // basic constructor
};

vector<int_vector> read_file(string file_name);

void sort_int_vector(vector<int_vector> v);

void output_vector(vector<int_vector> v);




#endif