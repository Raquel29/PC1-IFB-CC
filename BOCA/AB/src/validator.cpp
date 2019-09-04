#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int MIN_N = 2;
const int MAX_N = 1e5;

const double MIN_VALUE = 0.0;
const double MAX_VALUE = 10.0;


int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(MIN_N,MAX_N,"n");
    inf.readEoln();
    inf.readDoubles(n,MIN_VALUE,MAX_VALUE,"values");
    inf.readEoln();
    inf.readEof();
    return 0;
}