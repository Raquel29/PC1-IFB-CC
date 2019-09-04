#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int MIN_N = 1;
const int MAX_N = 20;
const int MAX_VALUE = 10000;
const int MIN_VALUE = 1;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(MIN_N,MAX_N,"n");
    inf.readEoln();
    while(n--){
        auto tc = inf.readInts(3,MIN_VALUE,MAX_VALUE,"values");
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}