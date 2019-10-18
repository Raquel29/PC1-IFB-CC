#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int MIN_L = 1;
const int MAX_L = 100;

const int MIN_C = 1;
const int MAX_C = 100;

const double MIN_VALUE = -100;
const double MAX_VALUE = 100;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int n, m;
    n = inf.readInt(MIN_L, MAX_L);
    inf.readSpace();
    m = inf.readInt(MIN_L, MAX_L);
    inf.readEoln();
    for (int i = 0; i < n; i++) {
        inf.readDoubles(m, MIN_VALUE, MAX_VALUE, "A[i][0..m]");
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}