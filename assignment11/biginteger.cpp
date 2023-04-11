#include <iostream>
#include <vector> 
#include <fstream>
#include <assert.h>

#include "biginteger.h"

using namespace std;

pair<bigint, bigint> product(pair<bigint, bigint> a, pair<bigint, bigint> b){
    pair<bigint, bigint> p;
    p.first = a.first * b.first;
    p.second = a.second * b.second;
    return p;
}

pair<bigint, bigint> sum(pair<bigint, bigint> a, pair<bigint, bigint> b){
    pair<bigint, bigint> s;
    s.first = (a.first * b.second) + (a.second * b.first);
    s.second = a.second * b.second;
    return s;
}

vector<vector<pair<bigint, bigint>>> make_matrix(string filename){

    vector<vector<pair<bigint, bigint>>> result;

    ifstream file(filename);

    int rows, cols;

    file >> rows >> cols;

    //cout << " reading rows : " << rows << " cols : " <<  cols << endl;

    for(int i = 0; i < rows ; i++){
        vector<pair<bigint, bigint>> r;
        for (int j = 0 ; j < cols ; j++){
            string numerator, denominator;
            file >> numerator >> denominator;
            bigint t1(numerator);
            bigint t2(denominator);

            r.push_back(make_pair(t1, t2));
        }
        result.push_back(r);
    }

    file.close();

    return result;

}

vector<vector<pair<bigint, bigint>>> matrix_mult(vector<vector<pair<bigint, bigint>>> x, vector<vector<pair<bigint, bigint>>> y){

    try {
        if (x[0].size() != y.size()) throw int(7);
        int rows = x.size();
        int cols = y[0].size();
        int n = y.size();

        vector<vector<pair<bigint, bigint>>> result(rows, vector<std::pair<bigint, bigint>>(cols));
        for(int i = 0 ; i < rows; i++){
            for(int j = 0; j < cols; j++){
                for(int k = 0 ; k < n ; k++){
                    pair<bigint, bigint> temp = product(x[i][k], y[k][j]);
                    if (result[i][j].first == bigint(0) && result[i][j].second == bigint(0)) result[i][j] = temp;
                    else result[i][j] = sum(result[i][j], temp);
                }
            }
        }
        return result;

    } catch (int i) {
        std::cout << "the matrices do not have the correct dimensions for multiplication" << endl;
        return {};

    }
}

bool equal_matrix(vector<vector<pair<bigint, bigint>>> x, vector<vector<pair<bigint, bigint>>> y){
    if (x.size() != y.size() && x[0].size() != y[0].size()) return false;
    for(int i = 0; i < x.size(); i++){
        for(int j = 0; j< x[0].size();j++){
            if ((x[i][j].first != y[i][j].first) ||( x[i][j].second != y[i][j].second)) return false;
        }
    }
    return true;
}

void print_matrix(vector<vector<pair<bigint, bigint>>> m){
    cout << "________________________________________________________________" << endl;
    for(int i = 0; i < m.size(); i++){
        for(int j = 0; j<m[i].size();j++){
            cout << "( " << m[i][j].first << " / " << m[i][j].second << " )";
        }
        cout << endl;
    }
    cout << "________________________________________________________________" << endl;

}
int main() {

    cout << endl;

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
    assert(p.first == bigint(9888 * 2));
    assert(p.second == bigint((111 * 1)));
    cout << "testing for product function PASSED" << endl << endl;


    pair<bigint, bigint> s = sum(fraction, two);
    assert(s.first == bigint((9888 * 1) + (111 * 2)));
    assert(s.second == bigint(111*1));
    cout << "testing for sum function PASSED" << endl << endl;

    vector<pair<bigint, bigint>> v;
    v.push_back(p);
    v.push_back(s);
    

    vector<vector<pair<bigint, bigint>>> v1 = make_matrix("matrix1.txt");
    cout << "matrix 1: " << endl;
    print_matrix(v1);
    vector<vector<pair<bigint, bigint>>> v2 = make_matrix("matrix2.txt");
    cout << "matrix 2: " << endl;
    print_matrix(v2);
    vector<vector<pair<bigint, bigint>>> v4 = make_matrix("badmatrix.txt");
    cout << "matrix 4: " << endl;
    print_matrix(v4);
    vector<vector<pair<bigint, bigint>>> v5 = make_matrix("matrix5.txt");
    cout << "matrix 5: " << endl;
    print_matrix(v5);




    assert(v1.size() == 3);
    assert(v1[0].size() == 3);
    assert(v2.size() == 3);
    assert(v2[0].size() == 2);
    assert(v4.size() == 1);
    assert(v4[0].size() == 1);
    assert(v5.size() == 2);
    assert(v5[0].size() == 3);
    cout << "testing for dimensions of make_matrix PASSED" << endl << endl;;
    assert(v1[0][0].second == bigint(1));
    assert(v2[0][0].first == bigint(1));
    assert(v2[0][0].second == bigint(2));
    assert(v2[1][1].first == bigint(7));
    assert(v2[1][1].second == bigint(8));
    cout << "testing for appropriate placement of values in matrix of make_matrix PASSED" << endl << endl;


    vector<vector<pair<bigint, bigint>>> v3 = matrix_mult(v1, v2);
    cout << "result of multiplying v1 and v2: " << endl;
    print_matrix(v3);
    vector<vector<pair<bigint, bigint>>> v6 = matrix_mult(v2, v5);
    cout << "result of multiplying v2 and v5: " << endl;
    print_matrix(v6);
    assert(v3.size() == 3);
    assert(v3[0].size() == 2);
    assert(v6.size() == 3);
    assert(v6[0].size() == 3);
    cout << "testing dimensions of result matrix of make_matrix PASSED" << endl << endl;



    vector<vector<pair<bigint, bigint>>> ev3 = make_matrix("expected_v3.txt");
    vector<vector<pair<bigint, bigint>>> ev6 = make_matrix("expected_v6.txt");
    assert(equal_matrix(v3, ev3));
    assert(equal_matrix(v6, ev6));
    cout << "testing for matrix structure of matrix_mult PASSED" << endl << endl;


    vector<vector<pair<bigint, bigint>>> v7 = matrix_mult(v1, v4);
    assert(v7.size() == 0);
    cout << "testing that try/catch handling for incompatible matrices of matrix_mult PASSED" << endl << endl;

}