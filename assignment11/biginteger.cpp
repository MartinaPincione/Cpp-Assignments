#include <iostream>
#include <vector> 
#include <fstream>
#include "bigint.h"

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

    cout << " reading rows : " << rows << " cols : " <<  cols << endl;

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
        cout << "new num rows: " << rows << endl;
        int cols = y[0].size();
        cout << "new num cols: " << cols << endl;
        int n = y.size();
        cout << n << endl;

        vector<vector<pair<bigint, bigint>>> result;

        for(int i = 0; i < rows ; i ++){
            vector<pair<bigint, bigint>> r;
            for(int j = 0; j < cols; j++){
                bigint t(0);
                r.push_back(make_pair(t, t));
            }
            result.push_back(r);
        }
        for(int i = 0 ; i < rows; i++){
            for(int j = 0; j < cols; j++){
                for(int k = 0 ; k < n ; k++){
                    cout << result[i][j].first << endl;
                    cout << x[i][k].first << endl; //see error here?
                    pair<bigint, bigint> temp = product(x[i][k], y[k][j]);
                    cout << temp.first << endl;
                    pair<bigint, bigint> previous = make_pair(result[i][j].first, result[i][j].second); // I even tried breaking it down
                    pair<bigint, bigint> temp2 = sum(previous, temp); // WHY GIVING ZERO HERE
                    cout << temp2.first << endl;
                    result[i][j] = sum(result[i][j], temp);
                }
            }
        }
        return result;

    } catch (int i) {
        std::cout << "the matrices do not have the correct dimensions for multiplication" << endl;
        return {};

    }
}


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
    std::cout << p.first <<  " " << p.second << endl;

    pair<bigint, bigint> s = sum(fraction, two);
    std::cout << s.first <<  " " << s.second << endl;

    vector<pair<bigint, bigint>> v;
    v.push_back(p);
    v.push_back(s);
    
    //std::cout << v[0].first << endl;

    vector<vector<pair<bigint, bigint>>> v1 = make_matrix("matrix1.txt");
    //std::cout << v1[0][0].first << endl;

    vector<vector<pair<bigint, bigint>>> v2 = make_matrix("matrix2.txt");
   //std::cout << v2[0][0].second << endl;


    vector<vector<pair<bigint, bigint>>> v3 = matrix_mult(v1, v2);
    std::cout << v3[0][0].first << endl;
}