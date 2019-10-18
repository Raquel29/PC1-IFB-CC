#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;


const int MIN_N = 1;
const int MAX_N = 30;

template <typename T> void append(vector<T> &dest, const vector<T> &orig) {
    dest.insert(dest.end(), orig.begin(), orig.end());
}

// Generate sample tests
vector<string> generate_sample_tests(void) {
    vector<string> tests = {"1\n","3\n","6\n"};
    return tests;
}


vector<string> generate_complete_tests(){
    vector<string> v;
    for(int i=MIN_N;i<=MAX_N;i++){
        if (i == 1 or i == 3 or i == 6)         // Remoção de testes repetidos
            continue;
            
        v.push_back(to_string(i)+"\n");
    }
    return v;
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
