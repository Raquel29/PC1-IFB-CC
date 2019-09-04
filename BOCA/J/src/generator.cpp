#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

const int MIN_N = 1;
const int MAX_N = 3999;

template <typename T> void append(vector<T> &dest, const vector<T> &orig) {
    dest.insert(dest.end(), orig.begin(), orig.end());
}

string output_tc(vector<int> &v) {
    ostringstream oss;
    oss << v.size() << endl;
    for (size_t i = 0; i < v.size(); i++) {
        oss << v[i];
        if (i < v.size() - 1)
            oss << " ";
    }
    oss << endl;
    return oss.str();
}

vector<string> generate_sample_tests() {
    vector<string> tests;
    vector<int> v = {1,7,48,99,MAX_N};
    tests.push_back(output_tc(v));
    return tests;
}

vector<string> generate_complete_tests() {
    vector<string> tests;
    vector<int> v;
    for(int i=MIN_N;i<=MAX_N;i++){
        v.push_back(i);
    }
    tests.push_back(output_tc(v));
    return tests;
}


int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    vector<string> tests;
    size_t test = 0;
    append(tests, generate_sample_tests());
    append(tests, generate_complete_tests());
    for (const auto &t : tests) {
        startTest(++test);
        cout << t;
    }
    return 0;
}