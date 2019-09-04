#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;


const int MIN_N = 1;
const int MAX_N = 1000;

const int MIN_M = 0;
const int MAX_M = 1e7;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(MIN_N,MAX_N,"n");
    inf.readEoln();
    inf.readInts(n,MIN_M,MAX_M,"values");
    inf.readEoln();
    inf.readEof();
    return 0;
}