#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const double MIN_V = 0;
const double MAX_V = 2*acos(-1);
const double PI = acos(-1.0);

const int rnd_test_n = 100;

template <typename T> void append(vector<T> &dest, const vector<T> &orig) {
	dest.insert(dest.end(), orig.begin(), orig.end());
}

string output_tc(double x) {
	ostringstream oss;
    oss << fixed << setprecision(2) << x << endl;
	return oss.str();
}


vector<string> generate_sample_tests() {
	vector<string> tests;
    tests.push_back(output_tc(0));
    tests.push_back(output_tc(PI/2));
    tests.push_back(output_tc(PI));
	return tests;
}



vector<string> generate_manual_tests() {
	vector<string> tests;
	tests.push_back(output_tc(3*PI/2));
	return tests;
}

string rnd_test(int i){
    return(output_tc(rnd.next(0.0,2*PI)));
}

vector<string> generate_random_tests() { 
    vector<string> tests;
    for (int i = 0; i < rnd_test_n; i++){
        tests.push_back(rnd_test(i));
    } 
    return tests;
}

int main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);
	vector<string> tests;
	size_t test = 0;
	append(tests, generate_sample_tests());
	append(tests, generate_manual_tests());
	append(tests, generate_random_tests());
	for (const auto &t : tests) {
		startTest(++test);
		cout << t;
	}
	return 0;
}