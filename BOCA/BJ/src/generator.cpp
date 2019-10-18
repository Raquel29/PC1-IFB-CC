#include <iostream>
#include <sstream>
#include <vector>

#include "testlib.h"

using namespace std;
using ll = long long;

vector<string> sample_tests {
    // Palíndromo
    "ABA\n",
    // Palíndromo fora de ordem
    "SUSMUM\n",
    // Não forma palíndromo
    "ABC\n",
};

vector<string> manual_tests {
    // Palíndromo ímpar
    "AABBB\n",
    // Todas as letras iguais
    "AAAAAAAAAAAA\n",
    // Uma única letra
    "X\n",
    // Não forma palíndromo
    "AB\n",
    "XYZ\n",
};

vector<string> generate_test(int qtd, int N)
{
    vector<string> tests;

    while (qtd--)
    {
        char pattern[256];

        switch (rnd.next(1, 3)) {
        case 1:
            sprintf(pattern, "[A-C]{%d,%d}", N, N);
            break;

        case 2:
            sprintf(pattern, "[A-E]{%d,%d}", N, N);
            break;

        default:
            sprintf(pattern, "[A-Z]{%d,%d}", N, N);
            break;
        }

        ostringstream os;
        os << rnd.next(string(pattern)) << endl;
        tests.push_back(os.str());
    }

    return tests;
}

void append(vector<string>& dest, const vector<string>& orig)
{
    dest.insert(dest.end(), orig.begin(), orig.end());
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    string cmd = argc > 1 ? argv[1] : "random";
    vector<string> tests;
    size_t test = 0;
 
    if (cmd == "samples")
        tests.insert(tests.end(), sample_tests.begin(), sample_tests.end());
    else if (cmd == "manual")
    {
        tests.insert(tests.end(), manual_tests.begin(), manual_tests.end());
        test += sample_tests.size();
    } else
    {
        int N = argc > 2 ? stoi(argv[2]) : 80;
        test += sample_tests.size();
        test += manual_tests.size();

        for (int k = 100000; k >= 1; k -= 1713)
        {
            auto more = generate_test(1, k);
            append(tests, more);
            N -= 1;
        }

        auto more = generate_test(N, 100);
        append(tests, more);
    }

    for (const auto& t : tests)
    {
        startTest(++test);
        cout << t;
    }
}
