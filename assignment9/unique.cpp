#include <iostream>
#include <vector> 
#include <memory>

#include "unique.h"


using namespace std;

bool verifyEqual(List* l, vector<int>& t){
    List::Node* n = l->head.get();

    // elements are pushed backwards so you have to iterate backwards
    for(int i = t.size() - 1; i >= 0 ; i--){
        if (!n) return false;
        if (n->data != t[i]) return false;
        n = n->next.get();
    }
    return true;

}

/* 
int main(){

    cout << "Welcome" << endl;

    List* list = (List*)malloc(sizeof(List));

    if (list->head == NULL) cout << "List is empty" << endl;

    list->push(10);
    list->push(5);

    cout << "Pushing 10 onto the head: " << list->head->next->data << endl;
    cout << "Pushing 5 onto the head: " << list->head->data << endl;

    vector<int> v {1, 2, 3, 4, 5, 6, 7, 8};


    for(auto element: v){
        cout << "inserting element " << element << " into the list " << endl;
        list->push(element);
    }

    delete(list);


    return 0;
} */
