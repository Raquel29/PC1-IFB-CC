#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;


const int MIN_N = 1;
const int MAX_N = 1e3;

const int MIN_M = 1;
const int MAX_M = 1e2;


vector<char> alphabet;

void initialize(){
    for(int i='a';i<='z';i++){
        alphabet.push_back(i);
    }
    alphabet.push_back(' ');
}


int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    initialize();
    string t = inf.readLine();
    ensuref(t.size()>=MIN_N && t.size()<=MAX_N,"size of text");
    for(auto c: t){
        ensuref(find(alphabet.begin(),alphabet.end(),c)!=alphabet.end(),"symbol not present in alphabet");
    }
    string p = inf.readLine("[a-z]{1,100}");
    inf.readEof();
    return 0;
}