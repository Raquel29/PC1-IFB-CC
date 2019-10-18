#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int MIN_N = 1;
const int MAX_N = 1e3;
const int random_test_n = 100;
const int extreme_test_n = 10;
const int almost_popstar_test_n = 10;

template <typename T> void append(vector<T> &dest, const vector<T> &orig) {
    dest.insert(dest.end(), orig.begin(), orig.end());
}

// Generate sample tests
vector<string> generate_sample_tests(void) {
    vector<string> tests = {"1\n1\n", "2\n1 1\n0 1\n",
                            "3\n0 1 0\n1 1 1\n0 1 1\n"};
    return tests;
}

string random_test(int num) {
    int min_n = MIN_N;
    int max_n = MAX_N;
    ostringstream os;
    if (num < random_test_n / 3) {
        // Easy
        min_n = 3;
        max_n = 10;

        // Polygon corner case
        if (num == 27) {
            min_n = 5;
        }
    } else if (num < 2 * random_test_n / 3) {
        // Medium
        min_n = 10;
        max_n = 100;
    } else {
        min_n = 100;
        max_n = 1000;
    }
    // 75%+ has celeb
    bool probably_has_celeb = rnd.next(1, 4) == 1 ? false : true;

    int n = rnd.next(min_n, max_n);

    vector<vector<int>> m(n, (vector<int>(n, 0)));
    if (probably_has_celeb) {
        int celeb = rnd.next(0, n - 1);
        m[celeb][celeb] = 1;
        for (int i = 0; i < n; i++) {
            if (i == celeb)
                continue;
            for (int j = 0; j < n; j++) {
                m[i][j] = j == celeb ? 1 : rnd.next(0, 1);
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m[i][j] = rnd.next(0, 1);
            }
        }
    }
    os << n << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            os << m[i][j];
            if (j < n - 1)
                os << " ";
            else
                os << endl;
        }
    }
    return os.str();
}

vector<string> generate_random_tests() {
    vector<string> v;
    for (int i = 1; i <= random_test_n; i++) {
        v.push_back(random_test(i));
    }
    return v;
}

string extreme_test() {
    int min_n = MAX_N;
    int max_n = MAX_N;
    ostringstream os;
    // 75%+ has celeb
    bool probably_has_celeb = rnd.next(1, 4) == 1 ? false : true;

    int n = rnd.next(min_n, max_n);

    vector<vector<int>> m(n, (vector<int>(n, 0)));
    if (probably_has_celeb) {
        int celeb = rnd.next(0, n - 1);
        m[celeb][celeb] = 1;
        for (int i = 0; i < n; i++) {
            if (i == celeb)
                continue;
            for (int j = 0; j < n; j++) {
                m[i][j] = j == celeb ? 1 : rnd.next(0, 1);
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m[i][j] = rnd.next(0, 1);
            }
        }
    }
    os << n << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            os << m[i][j];
            if (j < n - 1)
                os << " ";
            else
                os << endl;
        }
    }
    return os.str();
}

vector<string> generate_extreme_tests() {
    vector<string> v;
    for (int i = 1; i <= extreme_test_n; i++) {
        v.push_back(extreme_test());
    }
    return v;
}

string almost_popstar() {
    ostringstream os;
    int n = MAX_N;
    vector<vector<int>> m(n, vector<int>(n, 0));
    os << n << endl;
    int almost_popstar_idx = rnd.next(0, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = rnd.next(0, 1);
        }
    }
    for (int i = 0; i < n; i++) {
        m[i][almost_popstar_idx] = 1;
    }
    for (int i = 0; i < n; i++) {
        m[i][i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            os << m[i][j];
            if (j < n - 1)
                os << " ";
            else
                os << endl;
        }
    }
    return os.str();
}
vector<string> generate_almost_popstar_tests() {
    vector<string> v;
    for (int i = 0; i < almost_popstar_test_n; i++) {
        v.push_back(almost_popstar());
    }
    return v;
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    vector<string> tests;
    size_t test = 0;
    append(tests, generate_sample_tests());
    append(tests, generate_random_tests());
    append(tests, generate_extreme_tests());
    append(tests, generate_almost_popstar_tests());

    for (const auto &t : tests) {
        startTest(++test);
        cout << t;
    }
    return 0;
}
