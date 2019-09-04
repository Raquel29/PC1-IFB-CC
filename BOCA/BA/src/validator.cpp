#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int MIN_N = 1;
const int MAX_N  = 80;


int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    inf.readToken("[a-zA-Z]{1,80}");
    inf.readEoln();
    inf.readEof();
    return 0;
}