#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int MIN_N = 1;
const int MAX_N = 1e3;

const int MIN_V = -1e9;
const int MAX_V = 1e9;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(MIN_N,MAX_N,"n");
    inf.readEoln();
    inf.readInts(n,MIN_V,MAX_V,"values");
    inf.readEoln();
    inf.readEof();
    return 0;
}