#include <iostream>
#include <stack>
#include <fstream>
#include "stack_1.h"



stack<int> insert_to_stack(string f){

  stack<int> s;
  ifstream inputFile(f);

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


int check_sum_stack(stack<int> s){

  int sum= 0;
  while(!s.empty()){
    sum+= s.top();
    s.pop();
  }

  try {
    if(sum < 0) throw int(3);
    return 0;
  }
  catch(int i){
    cout << "Sum was negative" << endl;
    return 1;
  }


}