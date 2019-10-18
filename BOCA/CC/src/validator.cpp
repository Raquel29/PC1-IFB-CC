#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int MIN_N = 1;
const int MAX_N = 1e3;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(MIN_N, MAX_N, "n");
    inf.readEoln();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inf.readInt(0, 1,"value");
            if (j < n - 1)
                inf.readSpace();
            else
                inf.readEoln();
        }
    }
    inf.readEof();

    return 0;
}