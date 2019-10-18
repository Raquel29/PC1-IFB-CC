#include <iostream>
#include <sstream>
#include <vector>

#include "testlib.h"

using namespace std;
using ll = long long;

vector<string> sample_tests{
    // Exemplos pequenos
    "2 3\nMMM\nWMM\n",
    "5 5\nMMMMM\nMMMMM\nMMWMM\nMMMMM\nMMMMM\n",
};

vector<string> manual_tests{
    // Menores valores possíveis
    "1 1\nW\n",
};

vector<string> generate_test(int qtd) {
    vector<string> tests;

    while (qtd--) {
        auto N = rnd.next(1, 100);
        auto M = rnd.next(1, 100);

        vector<string> A(N, string(M, 'M'));

        auto x = rnd.next(1, N);
        auto y = rnd.next(1, M);

        A[x - 1][y - 1] = 'W';

        ostringstream os;
        os << N << ' ' << M << '\n';

        for (const auto &a : A)
            os << a << '\n';

        tests.push_back(os.str());
    }

    return tests;
}

void append(vector<string> &dest, const vector<string> &orig) {
    dest.insert(dest.end(), orig.begin(), orig.end());
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    vector<string> tests;
    size_t test = 0;

    tests.insert(tests.end(), sample_tests.begin(), sample_tests.end());
    tests.insert(tests.end(), manual_tests.begin(), manual_tests.end());
    int N = 150;
    auto more = generate_test(N);
    append(tests, more);

    for (const auto &t : tests) {
        startTest(++test);
        cout << t;
    }
    return 0;
}
