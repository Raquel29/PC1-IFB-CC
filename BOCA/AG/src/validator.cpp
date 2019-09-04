#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int MIN_N = 1;
const int MAX_N = 1e5;

const double MIN_V = -50.0;
const double MAX_V = 50.0;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(MIN_N,MAX_N,"n");
    inf.readEoln();
    auto v = inf.readDoubles(n,MIN_V,MAX_V,"values");
    inf.readEoln();
    inf.readEof();
    return 0;
}