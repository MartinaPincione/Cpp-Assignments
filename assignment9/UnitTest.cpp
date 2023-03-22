#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <algorithm>

#include "unique.h"
#include "doctest.h"

List* list1 = (List*)malloc(sizeof(List));
vector<int> v1{1, 2, 3, 4, 5};

List* list2 = (List*)malloc(sizeof(List));
vector<int> v2{};

List* list3 = (List*)malloc(sizeof(List));
vector<int> v3{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};


TEST_CASE("testing list 1"){

    vector<int> r1(v1.size());
    reverse_copy(v1.begin(), v1.end(), r1.begin());

    for(int i = 0; i < r1.size(); i++){
        list1->push(r1[i]);
    }

    CHECK(verifyEqual(list1, r1));


}

TEST_CASE("testing list 2"){
    vector<int> r2(v2.size());
    reverse_copy(v2.begin(), v2.end(), r2.begin());

    for(int i = 0; i < r2.size(); i++){
        list2->push(r2[i]);
    }
    CHECK(!list2->head);
    CHECK(verifyEqual(list2, r2));
}

TEST_CASE("testing list 3"){
    vector<int> r3(v3.size());
    reverse_copy(v3.begin(), v3.end(), r3.begin());

    for(int i = 0; i < r3.size(); i++){
        list3->push(r3[i]);
    }
    CHECK(verifyEqual(list3, r3));
}

TEST_CASE("freeing lists"){
    
    delete(list1);
    delete(list2);
    delete(list3);

}

