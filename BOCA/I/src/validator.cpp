#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;



const int MIN_N = 0;
const int MAX_N = 120;

const double MIN_M = 0;
const double MAX_M = 1000;

const int MIN_R = 0;
const int MAX_R = 2.0;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n;
    double m,r;
    inf.readDouble(MIN_M,MAX_M,"m");
    inf.readSpace();
    inf.readInt(MIN_N,MAX_N,"n");
    inf.readSpace();
    inf.readDouble(MIN_R,MAX_R,"r");
    inf.readEoln();
    inf.readEof();
    return 0;
}