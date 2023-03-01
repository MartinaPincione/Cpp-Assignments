#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <vector>

#include "doctest.h"
#include "perfect.h"

using namespace std;


TEST_CASE("testing components"){

    SUBCASE("testing deconstruct"){

        vector<int> vect(5,6);

        vector<int> deconstructed = deconstruct(vect);

        for(int i = 0; i < deconstructed.size(); i++){
            CHECK ( deconstructed[i] == (i + 1));
        }

        vector<int> vect2(27,28);

        vector<int> deconstructed2 = deconstruct(vect2);

        for(int i = 0; i < deconstructed2.size(); i++){
            CHECK ( deconstructed2[i] == (i + 1));
        }

    };
}

TEST_CASE("testing perfect integer"){

    vector<int> vect(5,6);
    CHECK ( divides_by_sum(vect, 6));

    vector<int> vect2(27,28);
    CHECK ( divides_by_sum(vect2, 28));


    vector<int> vect3(6,7);
    CHECK ( divides_by_sum(vect3, 7) == false);


    CHECK( 1 == 1);
}