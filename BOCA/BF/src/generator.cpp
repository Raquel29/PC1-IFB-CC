#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

const int MIN_N = 1;
const int MAX_N = 1000;

const int MIN_K = 0;
const int MAX_K = 95;

const int MIN_L = 1;
const int MAX_L = 80;

const int rnd_test_n = 100;
const int extreme_test_n = 100;

void cesar_encode(vector<string> &lines, int k) {
    for (auto &l : lines) {
        for (size_t i = 0; i < l.size(); i++) {
            l[i] = ' ' + ((l[i] - ' ' + k) % 95);
        }
    }
}

string generate_line(int n) {
    string s;
    for (int i = 0; i < n; i++) {
        s.push_back(32 + rnd.next(MIN_K, MAX_K - 1));
    }
    return s;
}

template <typename T> void append(vector<T> &dest, const vector<T> &orig) {
    dest.insert(dest.end(), orig.begin(), orig.end());
}

string output_tc(vector<string> vs, int k) {
    ostringstream oss;
    oss << vs.size() << " " << k << endl;
    cesar_encode(vs,k);
    for (auto line : vs) {
        oss << line << endl;
    }
    return oss.str();
}

vector<string> generate_sample_tests() {
    vector<string> tests;
    tests.push_back(output_tc({"abcdef"}, 3));
    tests.push_back(output_tc({"int main(void){", "    return 0;", "}"}, 3));
    tests.push_back(
        output_tc({"atirei o pau no gato", "mas o gato nao morreu", "5 bicas,",
                   "5 pipas,", "5 bombas.", "Tira da boca da bica,",
                   "bota na boca da bomba."},
                  10));
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

    int n = rnd.next(min_n, max_n);
    int k = rnd.next(MIN_K, MAX_K);
    vector<string> vs;
    for (int i = 0; i < n; i++) {
        vs.push_back(generate_line(rnd.next(MIN_L, MAX_L)));
    }
    return output_tc(vs, k);
}

vector<string> generate_manual_tests() {
    vector<string> tests;
    tests.push_back(output_tc({"uma vez flamento", "sempre flamengo"}, 95));
    return tests;
}
vector<string> generate_random_tests() {
    vector<string> tests;
    for (int i = 0; i < rnd_test_n; i++) {
        tests.push_back(rnd_test(i));
    }
    return tests;
}

string extreme_test() {
    vector<string> vs;
    for (int i = 0; i < MAX_N; i++) {
        vs.push_back(generate_line(MAX_L));
    }
    return output_tc(vs, rnd.next(MIN_K, MAX_K));
}

vector<string> generate_extreme_tests() {
    vector<string> tests;
    for (int i = 0; i < extreme_test_n; i++) {
        tests.push_back(extreme_test());
    }
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