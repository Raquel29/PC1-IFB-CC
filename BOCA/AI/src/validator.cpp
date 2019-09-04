#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;


const int MIN_N = 0;
const int MAX_N = 5;

const double MIN_C = -10.0;
const double MAX_C = 10.0;

const int MIN_Q = 1;
const int MAX_Q = 1e5;

const double MIN_VALUE = -1e2;
const double MAX_VALUE = 1e2;



int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(MIN_N,MAX_N,"n");
    inf.readEoln();
    inf.readDoubles(n+1,MIN_C,MAX_C,"coef");
    inf.readEoln();
    int q = inf.readInt(MIN_Q,MAX_Q,"q");
    inf.readEoln();
    for(int i=0;i<q;i++){
        inf.readDouble(MIN_VALUE,MAX_VALUE,"value");
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}