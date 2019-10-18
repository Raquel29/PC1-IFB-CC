#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;

const int MIN_N = 1;
const int MAX_N = 1000;

const int MIN_V = -100;
const int MAX_V = 100;

const int rnd_test_n = 100;

template <typename T> void append(vector<T> &dest, const vector<T> &orig) {
    dest.insert(dest.end(), orig.begin(), orig.end());
}

string output_tc(vvi &m) {
    ostringstream oss;
    oss << m.size() << endl;
    for (size_t i = 0; i < m.size(); i++) {
        for (size_t j = 0; j < m[i].size(); j++) {
            oss << m[i][j];
            oss << (j < m[i].size() - 1 ? " " : "\n");
        }
    }
    return oss.str();
}

vvi generate_random_matrix(int n, int min_v, int max_v) {
    int i, j;
    vvi m(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = rnd.next(min_v, max_v);
        }
    }
    return m;
}

vvi generate_biased_matrix(int n, int k, int min_v, int max_v) {
    auto m = generate_random_matrix(n, min_v, max_v);
    int i = (k < 0 ? -k : 0);
    int j = i+k;
    while (i < m.size() && j<m.size()) {
        m[i][j] = rnd.next(0, max_v);
        i++;
        j++;
    }
    return m;
}

vector<string> generate_sample_tests() {
    vector<string> tests;
    vvi m;
    m = {{2, 9}, {3, 3}};
    tests.push_back(output_tc(m));
    m = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    tests.push_back(output_tc(m));
    m = {{1, 4, -2}, {7, -4, 8}, {25, 10, 3}};
    tests.push_back(output_tc(m));
    return tests;
}

vector<string> generate_manual_tests() {
    vector<string> tests;
    return tests;
}

string rnd_test(int i) {
    int min_n = MIN_N;
    int max_n = MAX_N;

    int min_v = MIN_V;
    int max_v = MAX_V;

    if (i < rnd_test_n / 3) {
        max_n = 5;
        min_v = -10;
        max_v = 10;
    } else if (i < rnd_test_n / 2) {
        max_n = 50;
        min_v = -25;
        max_v = 25;
    }

    int n = rnd.next(MIN_N, max_n);
    int k = rnd.next(-(n - 1), n - 1);
    auto m = generate_biased_matrix(n, k, min_v, max_v);
    return (output_tc(m));
}

vector<string> generate_random_tests() {
    vector<string> tests;
    for (int i = 0; i < rnd_test_n; i++) {
        tests.push_back(rnd_test(i));
    }
    return tests;
}

string extreme_test_1() {
    auto m = generate_random_matrix(MAX_N, MIN_V, 0);
    m[m.size() - 1][m.size() - 1] = MAX_V;
    return output_tc(m);
}

string extreme_test_2() {
    auto m = generate_random_matrix(MAX_N, MIN_V, 0);
    m[m.size() - 1][0] = MAX_V;
    return output_tc(m);
}

string extreme_test_3() {
    auto m = generate_random_matrix(MAX_N, 0, 0);
    return output_tc(m);
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
    append(tests, generate_manual_tests());
    append(tests, generate_random_tests());
    append(tests, generate_extreme_tests());
    for (const auto &t : tests) {
        startTest(++test);
        cout << t;
    }
    return 0;
}