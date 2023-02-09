#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "stack_1.h"
#include "queue_1.h"
#include <stack>

using namespace std;

stack<int> s = insert_to_stack();
queue<int> q = insert_to_queue();

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


