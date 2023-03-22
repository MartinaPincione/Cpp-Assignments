#ifndef __UNIQUE_H_
#define __UNIQUE_H_

#include <iostream>
#include <vector> 
#include <memory>


using namespace std;


struct List
{
    struct Node {
        int data;
        unique_ptr<Node> next;
    };

    unique_ptr<Node> head;

    ~List() {
        cout << "Destructing the list" << endl;
        while(head) {
            cout << "destructing node containing " << head->data << endl;
            head = move(head->next);
        }
    }
    void push(int data) {
        unique_ptr<Node> temp = make_unique<Node>();
        temp->data = data;
        temp->next = move(head);
        head = move(temp);
    }

};


bool verifyEqual(List* l, vector<int>& t);

#endif