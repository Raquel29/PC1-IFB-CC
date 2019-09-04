#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

const int MIN_N = 0;
const int MAX_N = 120;

const double MIN_M = 0.0;
const double MAX_M = 1000.0;

const int MIN_R = 0.0;
const int MAX_R = 2.0;

const int rnd_test_n = 100;

template <typename T> void append(vector<T> &dest, const vector<T> &orig) {
	dest.insert(dest.end(), orig.begin(), orig.end());
}

string output_tc(double m, int n, double r) {
	ostringstream oss;
    oss << setprecision(2) << fixed << m << " ";
    oss  << n << " ";
    oss  << setprecision(2) << fixed << r << endl;
	return oss.str();
}


vector<string> generate_sample_tests() {
	vector<string> tests;
    tests.push_back(output_tc(0,20,2.0));
    tests.push_back(output_tc(10,55,1.5));
    tests.push_back(output_tc(1000,120,2.0));
	return tests;
}


string rnd_test(int i){
    int min_n = MIN_N;
    int max_n = MAX_N;

    double min_m = MIN_M;
    double max_m = MAX_M;
    
    double min_r = MIN_R;
    double max_r = MAX_R;
    
    int n;
    double m,r;
    n = rnd.next(MIN_N,MAX_N);
    m = rnd.next(MIN_M,MAX_M);
    r = rnd.next(MIN_R,MAX_R);
    return output_tc(m,n,r);
}

vector<string> generate_random_tests() { 
    vector<string> tests;
    for (int i = 0; i < rnd_test_n; i++){
        tests.push_back(rnd_test(i));
    } 
    return tests;
}

string extreme_test_1(){
    return(output_tc(1000.0,0,2.0));
}

string extreme_test_2(){
    return(output_tc(0,120,2.0));
}

string extreme_test_3(){
    return(output_tc(1000,120,2.0));
}
vector<string> generate_extreme_tests(){
    vector<string> tests;   
    tests.push_back(extreme_test_1());
    tests.push_back(extreme_test_2());
    tests.push_back(extreme_test_3());
    return tests;
}

int main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);
	vector<string> tests;
	size_t test = 0;
	append(tests, generate_sample_tests());
	append(tests, generate_random_tests());
	append(tests, generate_extreme_tests());
	for (const auto &t : tests) {
		startTest(++test);
		cout << t;
	}
	return 0;
}