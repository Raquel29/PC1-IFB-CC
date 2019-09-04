#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

const int MIN_N = 1;
const int MAX_N = 1e5;

const double MIN_V = -50.0;
const double MAX_V = 50.0;

const int rnd_test_n = 50;

template <typename T> void append(vector<T> &dest, const vector<T> &orig) {
    dest.insert(dest.end(), orig.begin(), orig.end());
}

string output_tc(vector<double> &temperatures) {
    ostringstream oss;
    oss << temperatures.size() << endl;
    for (size_t i = 0; i < temperatures.size(); i++) {
        oss << temperatures[i];
        oss << (i == temperatures.size() - 1 ? "\n" : " ");
    }
    return oss.str();
}

vector<double> generate_random_array(int n, double min_v = MIN_V,
                                     double max_v = MAX_V) {
    vector<double> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = rnd.next(min_v, max_v);
    }
    return v;
}

vector<string> generate_sample_tests() {
    vector<string> tests;
    vector<double> temperatures;
    temperatures = {25.0, 27.0, 26.0};
    tests.push_back(output_tc(temperatures));
    temperatures = {-10, 40, -10};
    tests.push_back(output_tc(temperatures));
    temperatures = {0, 0, 0};
    tests.push_back(output_tc(temperatures));
    return tests;
}

string rnd_test(int i) {
    int min_n = MIN_N;
    int max_n = MAX_N;
    if(i<= rnd_test_n-10){
        min_n = 1;
        max_n = 10;
    }
    int n = rnd.next(min_n, max_n);
    auto v = generate_random_array(n,MIN_V,MAX_V);
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
    auto v = generate_random_array(MAX_N,MIN_V,MAX_V); 
    return (output_tc(v)); 
}

string extreme_test_2() {
    auto v = generate_random_array(MAX_N,MAX_V,MAX_V); 
    return (output_tc(v)); 
}

string extreme_test_3() {
    auto v = generate_random_array(MAX_N,MIN_V,MIN_V); 
    return (output_tc(v)); 
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