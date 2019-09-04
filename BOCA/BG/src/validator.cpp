#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int MIN_N = 1;
const int MAX_N = 1e3;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    string s = inf.readLine("[a-z]+");
    ensuref(s.size()>=MIN_N && s.size()<=MAX_N,"line size");
    inf.readEof();
    return 0;
}