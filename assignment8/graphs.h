#ifndef __GRAPH_H_
#define __GRAPH_H_

#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>

using namespace std;


vector<vector<int>> readFileVertices(string fileName);

void printVector(vector<vector<int>> v);

bool verifyEqual(vector<vector<int>> v, vector<vector<int>> e);

#endif