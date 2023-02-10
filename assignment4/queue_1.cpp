#include <iostream>
#include <queue>
#include <fstream>
#include "queue_1.h"

queue<int> insert_to_queue(string f){

    queue<int> q;

    ifstream inputFile(f);

    int temp;
    while(inputFile >> temp){
        q.push(temp);
    }

    inputFile.close();

    return q;

}

int pop_from_queue(queue<int> q){
    int last_element;
    while(!q.empty()){
        last_element = q.front();
        q.pop();
    }
    return last_element;
}

 int check_sum_queue(queue<int> q){

  int sum= 0;
  while(!q.empty()){
    sum+= q.front();
    q.pop();
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