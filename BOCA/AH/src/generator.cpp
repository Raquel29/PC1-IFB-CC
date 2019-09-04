#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

const int MIN_N = 1;
const int MAX_N = 1e3;

const int MIN_V = -1e9;
const int MAX_V = 1e9;

const int rnd_test_n = 100;

template <typename T> void append(vector<T> &dest, const vector<T> &orig) {
    dest.insert(dest.end(), orig.begin(), orig.end());
}

string output_tc(vector<int> &v) {
    ostringstream oss;
    oss << v.size() << endl;
    for (size_t i = 0; i < v.size(); i++) {
        oss << v[i];
        oss << (i < v.size() - 1 ? " " : "\n");
    }
    return oss.str();
}

vector<string> generate_sample_tests() {
    vector<string> tests;
    vector<int> v;
    v = {1,1,1,1,1};
    tests.push_back(output_tc(v));
    v = {1,2,3,4,5};
    tests.push_back(output_tc(v));
    v = {2,-1,2,0,1,2};
    tests.push_back(output_tc(v));
    return tests;
}

vector<int> generate_random_array(int n,int min_v = MIN_V, int max_v = MAX_V){
    int prob = rnd.next(1,10);
    vector<int> v;
    for(int i=0;i<n;i++){
        int coin = rnd.next(1,10);
        if(i>0 && coin >= prob){
            v.push_back(rnd.any(v.begin(),v.end()));
        }
        else{
            v.push_back(rnd.next(min_v,max_v));
        }
    }
    return v;
}

string rnd_test(int i) {
    int min_n = MIN_N;
    int max_n = MAX_N;
    int min_v = MIN_V;
    int max_v = MAX_V;
    if (i < rnd_test_n / 3) {
        max_n = 10;
        max_v = 5;
        min_v = -5;
    } else if (i < rnd_test_n / 2) {
        max_n = 50;
        min_v = -20;
        max_v = 20;
    }
    int n = rnd.next(min_n,max_n);
    auto v = generate_random_array(n,min_v,max_v);
    return (output_tc(v));
}

vector<string> generate_random_tests() {
    vector<string> tests;
    for (int i = 0; i < rnd_test_n; i++) {
        tests.push_back(rnd_test(i));
    }
    return tests;
}

string extreme_test_1() {
    auto v = generate_random_array(MAX_N);
    return output_tc(v);
}

string extreme_test_2() {
    auto v = generate_random_array(MAX_N,MAX_V,MAX_V);
    return output_tc(v);
}

string extreme_test_3() {
    auto v = generate_random_array(MAX_N,MIN_V,MIN_V);
    return output_tc(v);
}

vector<string> generate_extreme_tests() {
    vector<string> tests;
    tests.push_back(extreme_test_1());
    tests.push_back(extreme_test_2());
    tests.push_back(extreme_test_3());
    return tests;
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    vector<string> tests;
    size_t test = 0;
    append(tests, generate_sample_tests());
    append(tests, generate_random_tests());
    append(tests, generate_extreme_tests());
    for (const auto &t : tests) {
        startTest(++test);
        cout << t;
    }
    return 0;
}