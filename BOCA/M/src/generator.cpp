#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

const int rnd_test_n = 100;

const int MIN_N = 1;
const int MAX_N = 20;
const int MAX_VALUE = 10000;
const int MIN_VALUE = 1;

template <typename T> void append(vector<T> &dest, const vector<T> &orig) {
    dest.insert(dest.end(), orig.begin(), orig.end());
}

string output_tc(vector<vector<int>> &v) {
    ostringstream oss;
    oss << v.size();
    oss << endl;
    for (auto value : v) {
        oss << value[0] << " " << value[1] << " " << value[2] << endl;
    }
    return oss.str();
}

vector<string> generate_sample_tests() {
    vector<string> tests;
    vector<vector<int>> v = {{1, 2, 3}, {6, 6, 14}, {1, 5, 7}, {33,9656, 6213}};
    tests.push_back(output_tc(v));
    return tests;
}

bool valid(vector<int> &v) {
    bool is_valid = true;
    for (auto value : v) {
        if (value > 10000 || value < 1) {
            is_valid = false;
        }
    }
    return is_valid;
}
vector<int> generate_valid_system() {
    vector<int> values(3);
    int x, y, z;
    do {
        x = rnd.next(-100, 100);
        y = rnd.next(-100, 100);
        z = rnd.next(-100, 100);
        values[0] = x + y + z;
        values[1] = x * y * z;
        values[2] = x * x + y * y + z * z;
    } while (!valid(values));
    return values;
}

vector<int> generate_random_system() {
    vector<int> values(3);
    for (int i = 0; i < 3; i++) {
        values[i] = rnd.next(MIN_N, MAX_N);
    }
    return values;
}

string rnd_test(int i) {
    int min_n = MIN_N;
    int max_n = MAX_N;

    int n = rnd.next(MIN_N, MAX_N);
    vector<vector<int>> v(n);
    for (size_t i = 0; i < v.size(); i++) {
        int has_solution = rnd.next(0, 10);
        if (has_solution) {
            v[i] = generate_valid_system();
        } else {
            v[i] = generate_random_system();
        }
    }
    return output_tc(v);
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