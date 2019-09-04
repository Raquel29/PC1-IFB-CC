#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5;
const int MIN_N = 1;
const int MIN_V = 0;
const int MAX_V = 46;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(MIN_N,MAX_N,"n");
    inf.readEoln();
    for(int k=0;k<n;k++){
        int i = inf.readInt(MIN_V,MAX_V,"i");
        inf.readSpace();
        int j = inf.readInt(i,MAX_V,"j");
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}