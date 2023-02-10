#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "stack_1.h"
#include "queue_1.h"
#include <stack>

using namespace std;

stack<int> s = insert_to_stack("nums.txt");
queue<int> q = insert_to_queue("nums.txt");

TEST_CASE("testing pushing to stack"){

  CHECK( 1 == 1 );
  CHECK(s.top() == 10);

}

TEST_CASE("testing popping from stack returns correct last element popped"){

  CHECK( pop_from_stack(s) == 1);

}

TEST_CASE("testing pushing onto queue"){

  CHECK( q.front() == 1);

}

TEST_CASE("testing popping from queue returns correct last element popped"){
  CHECK( pop_from_queue(q) == 10);
}

TEST_CASE("throwing exceptions"){

  SUBCASE("testing negative sum exceptions for stacks"){

    stack<int> s2 = insert_to_stack("nums2.txt");
    int compare1 = check_sum_stack(s2);
    CHECK (compare1 == 1);

    stack<int> s3 = insert_to_stack("nums.txt");
    int compare2 = check_sum_stack(s3);
    CHECK (compare2 == 0);

  };

  
  SUBCASE("testing negative sum exceptions for queues"){

    queue<int> q1 = insert_to_queue("nums2.txt");
    int compare1 = check_sum_queue(q1);
    CHECK (compare1 == 1);

    queue<int> q3 = insert_to_queue("nums.txt");
    int compare2 = check_sum_queue(q3);
    CHECK (compare2 == 0);

  };
  

}

