#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

const int MIN_N = 1;
const int MAX_N = 1e5;

const int MIN_VALUE = -1e5;
const int MAX_VALUE = 1e5;
const int rnd_test_n = 100;

template <typename T> void append(vector<T> &dest, const vector<T> &orig) {
    dest.insert(dest.end(), orig.begin(), orig.end());
}

string output_tc(vector<int> &v) {
    ostringstream oss;
    oss << v.size() << endl;
    for (size_t i = 0; i < v.size(); i++) {
        oss << v[i];
        oss << (i == v.size() - 1 ? "\n" : " ");
    }
    return oss.str();
}

vector<int> generate_random_array(int n = MAX_N, int min_v = MIN_VALUE,
                                  int max_v = MAX_VALUE) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = rnd.next(min_v, max_v);
    }
    return v;
}
vector<string> generate_sample_tests() {
    vector<string> tests;
    vector<int> v;
    v = {1, 2, 3, 4, 5};
    tests.push_back(output_tc(v));
    v = {-1, 2, -3, 4, -5};
    tests.push_back(output_tc(v));
    v = {0};
    tests.push_back(output_tc(v));
    return tests;
}

string rnd_test(int i) {
    int min_n = MIN_N;
    int max_n = MAX_N;
    int min_v = MIN_VALUE;
    int max_v = MAX_VALUE;

    if (i < rnd_test_n / 3) {
        max_n = 5;
        min_v = 0;
        max_v = 10;
    } else if (i < rnd_test_n / 2) {
        min_v = -100;
        max_v = 100;
        max_n = 20;
    }

    int n = rnd.next(min_n, max_n);
    vector<int> v = generate_random_array(n, min_v, max_v);
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
    vector<int> v = generate_random_array();
    return (output_tc(v));
}

vector<string> generate_extreme_tests() {
    vector<string> tests;
    tests.push_back(extreme_test_1());
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