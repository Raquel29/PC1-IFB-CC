#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;


int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    string s = inf.readToken("[a-z]+","string");
    ensuref(s.size() >0 && s.size()<=1000,"Tamanho da string.\n");
    inf.readEoln();
    inf.readEof();
    return 0;
}