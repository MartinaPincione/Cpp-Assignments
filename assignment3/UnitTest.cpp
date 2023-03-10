#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "linked_list.h"
using namespace std;


struct node * linked_list_1 = build_linked_list(0);

const int TEST_DELETE = 10;
struct node * linked_list_2 = build_linked_list(TEST_DELETE);

const int TEST_SMALL = 3;
struct node * linked_list_3 = build_linked_list(TEST_SMALL);

const int TEST_LARGE = 100;
struct node * linked_list_4 = build_linked_list(TEST_LARGE);

int check_sum(int num){
    int sum=0;
     for(int i = 0 ; i < num ; i++){
         sum+= i;
     }
     return sum;
}

TEST_CASE("Testing build of list") {


  CHECK( linked_list_1 == NULL);
  CHECK( linked_list_2 != NULL);
  CHECK( linked_list_3 != NULL);
  CHECK( linked_list_4 != NULL);
 

}

TEST_CASE("Testing summing of list elements"){

  CHECK( sum_values_in_linked_list(linked_list_1, 0) == 0);
  CHECK( sum_values_in_linked_list(linked_list_2, TEST_DELETE) == 45);
  CHECK( sum_values_in_linked_list(linked_list_3, TEST_SMALL) == 3);
  
}

TEST_CASE("Testing summing of list elements"){

  CHECK( sum_values_in_linked_list(linked_list_1, 0) == 0);
  CHECK( sum_values_in_linked_list(linked_list_2, TEST_DELETE) == check_sum(TEST_DELETE));
  CHECK( sum_values_in_linked_list(linked_list_3, TEST_SMALL) == check_sum(TEST_SMALL));
  CHECK( sum_values_in_linked_list(linked_list_4, TEST_LARGE) == check_sum(TEST_LARGE));
}

TEST_CASE("Testing deleting linked list") {
    CHECK( delete_linked_list(linked_list_2, TEST_DELETE) == TEST_DELETE );
    CHECK( delete_linked_list(linked_list_1, 0) == 0);
    CHECK( delete_linked_list(linked_list_3, TEST_SMALL) == TEST_SMALL);
    CHECK( delete_linked_list(linked_list_4, TEST_LARGE) == TEST_LARGE);
	   

}
