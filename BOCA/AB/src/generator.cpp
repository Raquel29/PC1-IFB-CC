#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

const int MIN_N = 2;
const int MAX_N = 1e5;

const double MIN_VALUE = 0.0;
const double MAX_VALUE = 10.0;

const int rnd_test_n = 100;

template <typename T> void append(vector<T> &dest, const vector<T> &orig) {
    dest.insert(dest.end(), orig.begin(), orig.end());
}

string output_tc(vector<double> &values) {
    ostringstream oss;
    oss << values.size() << endl;
    for (size_t i = 0; i < values.size(); i++) {
        oss << values[i];
        oss << (i < values.size() - 1 ? " " : "\n");
    }
    return oss.str();
}

vector<string> generate_sample_tests() {
    vector<string> tests;
    vector<double> values = {10.0, 10.0, 10.0};
    tests.push_back(output_tc(values));
    values = {0.0, 10.0, 5.0};
    tests.push_back(output_tc(values));
    values = {8.8, 4.3, 5.2, 0.0, 10.0, 7.7};
    tests.push_back(output_tc(values));
    return tests;
}

string rnd_test(int i) {
    int min_n = MIN_N;
    int max_n = MAX_N;

    if (i < rnd_test_n / 3) {
        max_n = 10;
    } else if (i < rnd_test_n / 2) {
        max_n = 100;
    }
    int n = rnd.next(MIN_N, max_n);
    vector<double> values;
    for (int i = 0; i < n; i++) {
        values.push_back(rnd.next(MIN_VALUE, MAX_VALUE));
    }
    return (output_tc(values));
}

vector<string> generate_random_tests() {
    vector<string> tests;
    for (int i = 0; i < rnd_test_n; i++) {
        tests.push_back(rnd_test(i));
    }
    return tests;
}

string extreme_test_1() {
    int n = MAX_N;
    vector<double> values;
    for (int i = 0; i < n; i++) {
        values.push_back(rnd.next(MIN_VALUE, MAX_VALUE));
    }
    return (output_tc(values));
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