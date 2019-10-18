#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvd = vector<vector<double>>;

const int MIN_L = 1;
const int MAX_L = 100;

const int MIN_C = 1;
const int MAX_C = 100;

const double MIN_VALUE = -100;
const double MAX_VALUE = 100;

const int rnd_test_n = 100;

template <typename T> void append(vector<T> &dest, const vector<T> &orig) {
    dest.insert(dest.end(), orig.begin(), orig.end());
}

string output_tc(vvd &A, vvd &B) {
    ostringstream oss;
    oss << A.size() << " " << A[0].size() << " " << B.size() << " "
        << B[0].size() << endl;
    for (size_t i = 0; i < A.size(); i++) {
        for (size_t j = 0; j < A[0].size(); j++) {
            oss << setprecision(2) << fixed << A[i][j];
            oss << (j < A[0].size() - 1 ? " " : "\n");
        }
    }
    for (size_t i = 0; i < B.size(); i++) {
        for (size_t j = 0; j < B[0].size(); j++) {
            oss << setprecision(2) << fixed << B[i][j];
            oss << (j < B[0].size() - 1 ? " " : "\n");
        }
    }
    return oss.str();
}

vvd generate_random_matrix(int n, int m, double min_v, double max_v) {
    vvd matrix(n, vector<double>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rnd.next(MIN_VALUE, MAX_VALUE);
        }
    }
    return matrix;
}

vector<string> generate_sample_tests() {
    vector<string> tests;
    vvd A, B;
    A = {{0, 1}, {1, 0}};
    B = {{1, 0}, {0, 1}};
    tests.push_back(output_tc(A, B));
    A = {{1, 2, 3}, {4, 5, 6}};
    B = {{1, 2}, {3, 4}, {5, 6}};
    tests.push_back(output_tc(A, B));
    A = {{1.5, -2.3, 0}, {3.1, -2.7, -3.14}};
    B = {{1, 1, 1}, {1, 1, 1}};
    tests.push_back(output_tc(A, B));
    return tests;
}

vector<string> generate_manual_tests() {
    vector<string> tests;
    return tests;
}

string rnd_test(int i) {
    int min_n = MIN_L;
    int max_n = MAX_L;

    if (i < rnd_test_n / 3) {
        max_n = 5;
    } else if (i < rnd_test_n / 2) {
        max_n = 10;
    }
    int n = rnd.next(min_n, max_n);
    int m = rnd.next(min_n, max_n);
    int k, l;
    bool has_product = rnd.next(0, 1);
    k = has_product ? m : rnd.next(min_n, max_n);
    l = rnd.next(min_n, max_n);
    auto A = generate_random_matrix(n, m, MIN_VALUE, MAX_VALUE);
    auto B = generate_random_matrix(k, l, MIN_VALUE, MAX_VALUE);
    return output_tc(A, B);
}

vector<string> generate_random_tests() {
    vector<string> tests;
    for (int i = 0; i < rnd_test_n; i++) {
        tests.push_back(rnd_test(i));
    }
    return tests;
}

string extreme_test_1() {
    auto A = generate_random_matrix(MAX_L, MAX_L, 0, 0);
    auto B = generate_random_matrix(MAX_L, MAX_L, 0, 0);
    return (output_tc(A, B));
}

string extreme_test_2() {
    auto A = generate_random_matrix(MAX_L, MAX_L, MIN_VALUE, MAX_VALUE);
    auto B = generate_random_matrix(MAX_L, MAX_L, MIN_VALUE, MAX_VALUE);
    return (output_tc(A, B));
}

vector<string> generate_extreme_tests() {
    vector<string> tests;
    tests.push_back(extreme_test_1());
    tests.push_back(extreme_test_2());
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