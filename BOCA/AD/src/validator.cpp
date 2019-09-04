#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;



const int MIN_N = 2;
const int MAX_N = 1000;

const double MIN_V = -1000;
const double MAX_V = 1000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(MIN_N,MAX_N,"n");
    inf.readEoln();
    auto x = inf.readDoubles(n,MIN_V,MAX_V,"x");
    inf.readEoln();
    auto y = inf.readDoubles(n,MIN_V,MAX_V,"y");
    inf.readEoln();
    inf.readEof();
    return 0;
}