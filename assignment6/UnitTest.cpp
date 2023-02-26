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

    SUBCASE("testing the struct constructor"){
        
        int_vector new_vector;
        CHECK(new_vector.id == -1);
        CHECK(new_vector.to == 0);
        CHECK(new_vector.from == 0);

    };


    SUBCASE("testing the copy constructor on vectors_2D.txt"){
        
        vector<int_vector> v1 = read_file("vectors_2D.txt");

        CHECK( v1.size() == 5);
        
        for(int i = 0; i < 4 ; i ++ ){
            CHECK( v1[i].id == i);
        }

    };

    SUBCASE("testing the copy constructor on vector_empty.txt"){
        
        vector<int_vector> v2 = read_file("vector_empty.txt");
        
        CHECK( v2.size() == 0);
        
    };
}