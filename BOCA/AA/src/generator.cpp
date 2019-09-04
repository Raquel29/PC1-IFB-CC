#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
vector<bool> prime;

const int MIN_VALUE = 1;
const int MAX_VALUE = 1e7;
const int LAST_PRIME = 9999991;
const int MIN_N = 1;
const int MAX_N = 1e5;

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

string output_tc(vector<int> &numbers) {
    ostringstream oss;
    oss << numbers.size() << endl;
    for (size_t i = 0; i < numbers.size(); i++) {
        oss << numbers[i] << endl;
    }
    return oss.str();
}

vector<string> generate_sample_tests() {
    vector<string> tests;
    vector<int> numbers = {2, 4, 11, 15, 23};
    tests.push_back(output_tc(numbers));
    return tests;
}

string rnd_test(int i) {
    int n = rnd.next(MIN_N,MAX_N);
    vector<int> numbers(n);
    for(int i=0;i<n;i++){
        bool coin = rnd.next(0, 1);
        int number;
        if (coin) {
            do {
                number = rnd.next(MIN_VALUE, MAX_VALUE);
            } while (!prime[number]);
        } else {
            number = rnd.next(MIN_VALUE, MAX_VALUE);
        }
        numbers[i] = number;
    }
    return (output_tc(numbers));
}

vector<string> generate_random_tests() {
    vector<string> tests;
    for (int i = 0; i < rnd_test_n; i++) {
        tests.push_back(rnd_test(i));
    }
    return tests;
}

vector<string> generate_manual_tests() {
    vector<string> tests;
    vector<int> numbers = {1, 2};
    tests.push_back(output_tc(numbers));
    return tests;
}

string extreme_test_1() {
    vector<int> number = {MAX_VALUE};
    return (output_tc(number));
}

string extreme_test_2() {
    vector<int> numbers;
    for (int i = 0; i < MAX_N; i++) {
        numbers.push_back(LAST_PRIME);
    }
    return output_tc(numbers);
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
    erastostenes(MAX_VALUE);
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