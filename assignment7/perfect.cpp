#include <iostream>

#include "perfect.h"

using namespace std;



vector<int> deconstruct(vector<int> v){
    vector<int> result;
    for (int i = 0 ; i < v[0]; i++){
        result.push_back(i + 1);
    }
    return result;
}

bool divides_by_sum(const vector<int> & v, const int & d){

    int sum = 0;

    vector<int> finding_sum;

    vector<int> iter = deconstruct(v);

    for_each(iter.begin(), iter.end(), [&finding_sum, d](int & a){
        if ((d % a) == 0) finding_sum.push_back(a);
    });

    finding_sum.pop_back();

    for(auto i : finding_sum){
        sum += i;
    }

    return (sum == v[1]);

}