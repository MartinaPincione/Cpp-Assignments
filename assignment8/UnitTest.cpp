#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>

#include "doctest.h"
#include "graphs.h"

using namespace std;

const string graph1 = "graph1.txt";
const string graph2 = "graph2.txt";

TEST_CASE("testing graph1.txt"){

    vector<vector<int>> g1 = readFileVertices(graph1);

    vector<vector<int>> e1{{1, 2}, {2, 0}, {1, 0}};
    cout << "from input: " << endl;
    printVector(g1);
    cout << "expected: " << endl;
    printVector(e1);

    bool result1 = verifyEqual(g1, e1);

    CHECK( result1 );

}

TEST_CASE("testing empty file"){
    vector<vector<int>> g2 = readFileVertices(graph2);

    vector<vector<int>> e2 {};

    
    CHECK(g2.size() == 0);

    CHECK(verifyEqual(g2, e2));

}