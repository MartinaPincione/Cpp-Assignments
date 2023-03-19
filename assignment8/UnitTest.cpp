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
const string graph3 = "graph3.txt";

TEST_CASE("testing graph1.txt"){

    vector<vector<int>> g1 = readFileVertices(graph1);

    vector<vector<int>> e1{{1, 2}, {2, 0}, {1, 0}};
    cout << "from input: " << endl;
    printVector(g1);
    cout << "expected: " << endl;
    printVector(e1);

    CHECK( verifyEqual(g1, e1) );

}

TEST_CASE("testing empty file"){
    vector<vector<int>> g2 = readFileVertices(graph2);

    vector<vector<int>> e2 {};

    
    CHECK(g2.size() == 0);

    CHECK(verifyEqual(g2, e2));

}

TEST_CASE("testing graph 3"){

    vector<vector<int>> g3 = readFileVertices(graph3);

    vector<vector<int>> e3 {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};

    cout << "from input: " << endl;
    printVector(g3);
    cout << "expected: " << endl;
    printVector(e3);

    CHECK(verifyEqual(g3, e3));
}