#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

const int MIN_N = 1;
const int MAX_N = 1e3;

const int MIN_M = 1;
const int MAX_M = 1e2;

const int rnd_test_n = 100;

vector<char> alphabet;

void initialize() {
    for (int i = 'a'; i <= 'z'; i++) {
        alphabet.push_back(i);
    }
    alphabet.push_back(' ');
}
template <typename T> void append(vector<T> &dest, const vector<T> &orig) {
    dest.insert(dest.end(), orig.begin(), orig.end());
}

string output_tc(string x, string y) {
    ostringstream oss;
    oss << x << endl << y << endl;
    return oss.str();
}

string generate_pattern(int m) {
    pattern pregex("[a-z]{" + to_string(m) + "," + to_string(m) + "}");
    return pregex.next(rnd);
}

// Create text with non overlaping pattern occurrences
string generate_text(int n, string &p) {
    string t;
    t.resize(n);
    vector<size_t> occ;

    int pos = -1;
    while (pos < n - (int)p.size()) {
        pos = rnd.next(pos + 1, n - (int)p.size());
        occ.push_back(pos);
        pos+=p.size();
    }
    for (size_t i = 0, j = 0; i < n;) {
        if (j<occ.size() && i == occ[j]) {
            for (size_t k = 0; k < p.size(); k++) {
                t[i + k] = p[k];
            }
            i+=p.size();
            j++;
        } else {
            t[i++] = rnd.any(alphabet);
        }
    }
    return t;
}

vector<string> generate_sample_tests() {
    vector<string> tests;
    tests.push_back(output_tc("abracadabra", "abra"));
    tests.push_back(output_tc("aacacatgacagtaacata", "aca"));
    tests.push_back(output_tc("aaaaaaaa", "a"));
    return tests;
}

vector<string> generate_manual_tests() {
    vector<string> tests;
    tests.push_back(output_tc(
        "era um garoto que como eu amava os beatles e os rolling stones",
        "os"));
    tests.push_back(output_tc("ta ta tatata ta ta ta ta ta", "nao"));
    return tests;
}

string rnd_test(int i) {
    int min_n = MIN_N;
    int max_n = MAX_N;

    int min_m = MIN_M;
    int max_m = MAX_M;

    if (i < rnd_test_n / 3) {
        max_m = 5;
        max_n = 10;
    } else if (i < rnd_test_n / 2) {
        max_m = 10;
        max_n = 50;
    }

    int n = rnd.next(min_n, max_n);
    int m = rnd.next(min_m, min(n, max_m));
    auto p = generate_pattern(m);
    auto t = generate_text(n, p);
    return (output_tc(t, p));
}

vector<string> generate_random_tests() {
    vector<string> tests;
    for (int i = 0; i < rnd_test_n; i++) {
        tests.push_back(rnd_test(i));
    }
    return tests;
}

string extreme_test_1() {
    return output_tc(rnd.next("[ab]{%d,%d}", MAX_N, MAX_N),
                     rnd.next("[ab]{%d,%d}", MIN_M, MAX_M));
}

string extreme_test_2() {
    return output_tc(rnd.next("[ab]{%d,%d}", MAX_N, MAX_N),
                     rnd.next("[ab]{%d,%d}", MAX_M, MAX_M));
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
    initialize();
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