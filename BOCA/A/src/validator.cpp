#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int MIN_N = 0;
const int MAX_N = 1e5;

const int MIN_V = -1e5;
const int MAX_V = 1e5;

const int rnd_test_n = 100;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1,MAX_N,"n");
    inf.readEoln();
    auto v = inf.readInts(n,MIN_V,MAX_V,"values");
    inf.readEoln();
    inf.readEof();
    return 0;
}