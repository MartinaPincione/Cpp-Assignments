#include <iostream>
#include <stack>
#include <fstream>
#include "stack_1.h"



stack<int> insert_to_stack(){

  stack<int> s;
  ifstream inputFile("nums.txt");

  int temp;
  while(inputFile >> temp){
    s.push(temp);
  }

  inputFile.close();

  return s;
}

int pop_from_stack(stack<int> s){
  int last_element;
  while (!s.empty()){
    last_element = s.top();
    s.pop();
  }
  return last_element;
}
