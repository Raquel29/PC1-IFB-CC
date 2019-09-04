#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

template <typename T> void append(vector<T> &dest, const vector<T> &orig) {
	dest.insert(dest.end(), orig.begin(), orig.end());
}


const int MAX_N = 99;
const int MIN_N = 1;

string output_tc(int x){
    ostringstream oss;
    oss << x << endl;
    return oss.str();
}

vector<string> generate_complete_tests(){
    vector<string> vs;
    for(int i=MIN_N;i<=MAX_N;i+=2){
        vs.push_back(output_tc(i));
    }
    return vs;
}

int main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);
	vector<string> tests;
	size_t test = 0;
	append(tests, generate_complete_tests());
	for (const auto &t : tests) {
		startTest(++test);
		cout << t;
	}
	return 0;
}