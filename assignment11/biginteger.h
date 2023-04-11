#ifndef __BIGINTEGER_H_
#define __BIGINTEGER_H_

#include <iostream>
#include <vector> 
#include <fstream>

#include "bigint.h"

using namespace std;

pair<bigint, bigint> product(pair<bigint, bigint> a, pair<bigint, bigint> b);

pair<bigint, bigint> sum(pair<bigint, bigint> a, pair<bigint, bigint> b);

vector<vector<pair<bigint, bigint>>> make_matrix(string filename);

vector<vector<pair<bigint, bigint>>> matrix_mult(vector<vector<pair<bigint, bigint>>> x, vector<vector<pair<bigint, bigint>>> y);

void print_matrix(vector<vector<pair<bigint, bigint>>> m);

bool equal_matrix(vector<vector<pair<bigint, bigint>>> x, vector<vector<pair<bigint, bigint>>> y);

#endif