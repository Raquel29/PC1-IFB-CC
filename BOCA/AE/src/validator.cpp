#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int MIN_N = 1;
const int MAX_N = 1e5;

const int MIN_VALUE = -1e5;
const int MAX_VALUE = 1e5;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(MIN_N,MAX_N,"n");
    inf.readEoln();
    auto v = inf.readInts(n,MIN_VALUE,MAX_VALUE,"values");
    inf.readEoln();
    inf.readEof();
    return 0;
}