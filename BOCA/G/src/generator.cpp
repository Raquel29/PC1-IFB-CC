#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
vector<bool> prime;

const int MIN_N = 1;
const int MAX_N = 2147483647;

void erastostenes(size_t n) {
    prime.assign(n + 1, true);
    prime[0] = prime[1] = false;

    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

const int rnd_test_n = 100;

template <typename T> void append(vector<T> &dest, const vector<T> &orig) {
    dest.insert(dest.end(), orig.begin(), orig.end());
}

string output_tc(int x) {
    ostringstream oss;
    oss << x << endl;
    return oss.str();
}

vector<string> generate_sample_tests() {
    vector<string> tests;
    tests.push_back(output_tc(2));
    tests.push_back(output_tc(1));
    tests.push_back(output_tc(27));
    return tests;
}

string rnd_test(int i) {
    int max_n = MAX_N;
    if (i < rnd_test_n / 3) {
        max_n = 100;
    } else if (i < rnd_test_n / 2) {
        max_n = 1000;
    }
    int n;
    bool coin = rnd.next(0, 1);
    if (coin) {
        do {
            n = rnd.next(MIN_N, max_n);
        } while (!prime[n]);
    } else {
        n = rnd.next(MIN_N, max_n);
    }
    return (output_tc(n));
}

vector<string> generate_random_tests() {
    vector<string> tests;
    for (int i = 0; i < rnd_test_n; i++) {
        tests.push_back(rnd_test(i));
    }
    return tests;
}

string extreme_test_1() { return (output_tc(2147483647)); }

vector<string> generate_extreme_tests() {
    vector<string> tests;
    tests.push_back(extreme_test_1());
    return tests;
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    vector<string> tests;
    size_t test = 0;
    erastostenes(MAX_N);
    append(tests, generate_sample_tests());
    append(tests, generate_random_tests());
    append(tests, generate_extreme_tests());
    for (const auto &t : tests) {
        startTest(++test);
        cout << t;
    }
    return 0;
}