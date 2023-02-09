#include <iostream>
#include <queue>
#include <fstream>
#include "queue_1.h"

queue<int> insert_to_queue(){

    queue<int> q;

    ifstream inputFile("nums.txt");

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