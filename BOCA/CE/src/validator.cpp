#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int MIN_N = 1;
const int MAX_N = 1000;

const int MIN_V = -100;
const int MAX_V = 100;


int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(MIN_N,MAX_N,"n");
    inf.readEoln();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            inf.readInt(MIN_V,MAX_V,"A[i][j]");
            if(j<n-1){
                inf.readSpace();
            }
        }
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}