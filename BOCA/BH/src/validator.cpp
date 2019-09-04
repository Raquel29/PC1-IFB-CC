#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int MIN_N = 1;
const int MAX_N = 1e3;


string rle_decode(string s) {
    size_t i = 0;
    ostringstream oss;
    while (i < s.size()) {
        int num = 0;
        while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
            num *= 10;
            num += s[i] - '0';
            i++;
        }
        for (int j = 0; j < num; j++) {
            oss << s[i];
        }
        i++;
    }
    return oss.str();
}

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    string s = inf.readLine("[a-z0-9]+");
    ensuref(s.size()>=MIN_N && s.size()<=MAX_N,"line size");
    ensuref(rle_decode(s).size()<=MAX_N,"output size has to be <= %d",MAX_N);
    inf.readEof();
    return 0;
}