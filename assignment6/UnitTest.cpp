#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

#include "doctest.h"
#include "vector_sort.h"

using namespace std;



TEST_CASE("testing vectors_2D.txt"){


    vector<int_vector> v2 = read_file("vector_2D.txt");
    CHECK( v2.size() > 0);
}