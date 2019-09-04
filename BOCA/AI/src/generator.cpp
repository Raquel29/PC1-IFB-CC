#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int MIN_N = 0;
const int MAX_N = 5;

const double MIN_C = -10.0;
const double MAX_C = 10.0;

const int MIN_Q = 1;
const int MAX_Q = 1e5;

const double MIN_VALUE = -1e2;
const double MAX_VALUE = 1e2;

const int rnd_test_n = 100;

template <typename T> void append(vector<T> &dest, const vector<T> &orig) {
    dest.insert(dest.end(), orig.begin(), orig.end());
}

vector<double> generate_random_array(int n,double min_v,double max_v){
    vector<double> v(n);
    for(size_t i=0;i<n;i++){
        v[i] = rnd.next(min_v,max_v);
    }
    return v;
}

string output_tc(vector<double> &coef, vector<double> &x) {
    ostringstream oss;
    oss << coef.size()-1 << endl;
    for (size_t i = 0; i < coef.size(); i++) {
        oss <<  setprecision(1) << fixed << coef[i];
        oss << (i == coef.size()-1 ? "\n" : " ");
    }
    oss << x.size() << endl;
    for (size_t i = 0; i < x.size(); i++) {
        oss << setprecision(1) << fixed << x[i];
        oss << endl;
    }
    return oss.str();
}


vector<string> generate_sample_tests() {
    vector<string> tests;
    vector<double> coef,x;
    coef = {2.5};
    x = {1.0,2.0,3.0};
    tests.push_back(output_tc(coef,x));
    coef = {0,0,2};
    x = {-1.0,0.0,1.0};
    tests.push_back(output_tc(coef,x));
    coef = {5,4,3,2,1};
    x = {2.5,0,-2.2,4.9};
    tests.push_back(output_tc(coef,x));
    return tests;
}


string rnd_test(int i) {
    int min_n = MIN_N;
    int max_n = MAX_N;

    double min_c = MIN_C;
    double max_c = MAX_C;

    int min_q = MIN_Q;
    int max_q = MAX_Q;

    double min_v = MIN_VALUE;
    double max_v = MAX_VALUE;

    if(i<rnd_test_n/3){
        max_q = 10;
    }
    else if(i<rnd_test_n/2){
        max_q = 100;
    }

    int n = rnd.next(min_n,max_n);
    auto coef = generate_random_array(n+1,min_c,max_c);
    int q = rnd.next(min_q,max_q);
    auto x  = generate_random_array(q,min_v,max_v);
    return output_tc(coef,x);
}

vector<string> generate_random_tests() {
    vector<string> tests;
    for (int i = 0; i < rnd_test_n; i++) {
        tests.push_back(rnd_test(i));
    }
    return tests;
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    vector<string> tests;
    size_t test = 0;
    append(tests, generate_sample_tests());
    append(tests, generate_random_tests());
    for (const auto &t : tests) {
        startTest(++test);
        cout << t;
    }
    return 0;
}