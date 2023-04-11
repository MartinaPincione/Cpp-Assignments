#include <iostream>
#include <vector> 
#include <fstream>
#include <assert.h>

#include "biginteger.h"

using namespace std;

int main() {

    pair<bigint, bigint> fraction, two;

    bigint a("9888");
    bigint b("111");
    fraction.first = a;
    fraction.second = b;

    bigint d("2");
    bigint e("1");
    two.first = d;
    two.second = e;

    pair<bigint, bigint> p = product(fraction, two);
    assert(p.first == ((fraction.first * two.first)));
    assert(p.second == (fraction.second * two.second));

    //std::cout << p.first <<  " " << p.second << endl;

    pair<bigint, bigint> s = sum(fraction, two);
    assert(s.first == ((fraction.first * two.second) + (fraction.second * two.first)));
    //std::cout << s.first <<  " " << s.second << endl;

    vector<pair<bigint, bigint>> v;
    v.push_back(p);
    v.push_back(s);
    
    //std::cout << v[0].first << endl;

    vector<vector<pair<bigint, bigint>>> v1 = make_matrix("matrix1.txt");
    assert(v1.size() == 3);
    assert(v1[0].size() == 3);
    print_matrix(v1);

    //std::cout << v1[0][0].first << endl;

    vector<vector<pair<bigint, bigint>>> v2 = make_matrix("matrix2.txt");
    assert(v2.size() == 3);
    assert(v2[0].size() == 2);
    print_matrix(v2);

   //std::cout << v2[0][0].second << endl;


    vector<vector<pair<bigint, bigint>>> v3 = matrix_mult(v1, v2);
    assert(v3.size() == 3);
    assert(v3[0].size() == 2);
    vector<vector<pair<bigint, bigint>>> ev3 = make_matrix("expected_v3.txt");
    assert(equal_matrix(v3, ev3));
    print_matrix(v3);

    std::cout << v3[0][0].first << endl;

    vector<vector<pair<bigint, bigint>>> v4 = make_matrix("badmatrix.txt");
    assert(v4.size() == 1);
    assert(v4[0].size() == 1);

    vector<vector<pair<bigint, bigint>>> v5 = matrix_mult(v1, v4);
    assert(v5.size() == 0);
}