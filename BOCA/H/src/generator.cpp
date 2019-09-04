#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

const int MIN_N = 0;
const int MAX_N = 100;


const int rnd_test_n = 100;

template <typename T> void append(vector<T> &dest, const vector<T> &orig) {
	dest.insert(dest.end(), orig.begin(), orig.end());
}

string output_tc(int x) {
	ostringstream oss;
    oss << x << endl;
	return oss.str();
}


vector<string> generate_sample_tests() {
	vector<string> tests;
    tests.push_back(output_tc(1));
    tests.push_back(output_tc(2));
    tests.push_back(output_tc(3));
	return tests;
}



vector<string> generate_complete_tests() {
	vector<string> tests;
    for(int i=4;i<=MAX_N;i++){
        tests.push_back(output_tc(i));
    }
	return tests;
}


int main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);
	vector<string> tests;
	size_t test = 0;
	append(tests, generate_sample_tests());
	append(tests, generate_complete_tests());
	for (const auto &t : tests) {
		startTest(++test);
		cout << t;
	}
	return 0;
}