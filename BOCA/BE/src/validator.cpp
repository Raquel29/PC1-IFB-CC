#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;


const int MIN_N = 1;
const int MAX_N = 1000;

const int MIN_K = 0;
const int MAX_K = 95;

const int MIN_L = 1;
const int MAX_L = 80;



int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n,k;
    n = inf.readInt(MIN_N,MAX_N,"n");
    inf.readSpace();
    inf.readInt(MIN_K,MAX_K,"k");
    inf.readEoln();
    for(int i=0;i<n;i++){
        string line = inf.readLine();
        ensuref(line.size()>=1 && line.size()<=80,"1<= |L| <=80 must be attended");
        for(auto c: line){
            ensuref(c>=32 && c<=126,"invalid character");
        }
    }
    inf.readEof();
    return 0;
}