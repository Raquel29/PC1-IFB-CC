#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int MIN_N = 1;
const int MAX_N = 3999;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(MIN_N,MAX_N,"n");
    inf.readEoln();
    vector<int> v = inf.readInts(n,MIN_N,MAX_N,"v");
    inf.readEoln();
    inf.readEof();
    return 0;
}