#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;


const int MAX_N = 99;
const int MIN_N = 1;


int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(MIN_N,MAX_N,"n");
    ensuref(n & 1, "n must be odd");
    inf.readEoln();
    inf.readEof();
    return 0;
}