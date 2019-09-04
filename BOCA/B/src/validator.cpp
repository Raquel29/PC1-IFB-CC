#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const double MIN_V = 0;
const double MAX_V = 2*acos(-1);

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    inf.readDouble(MIN_V,MAX_V,"x");
    inf.readEoln();
    inf.readEof();
    return 0;
}