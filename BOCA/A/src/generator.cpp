#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

const int MIN_N = 0;
const int MAX_N = 1e5;

const int MIN_V = -1e5;
const int MAX_V = 1e5;

const int rnd_test_n = 100;

template <typename T> void append(vector<T> &dest, const vector<T> &orig) {
	dest.insert(dest.end(), orig.begin(), orig.end());
}

string output_tc(vector<int>& v) {
	ostringstream oss;
    oss << v.size() << endl;
    for(size_t i=0;i<v.size();i++){
        oss << v[i];
        oss << (i==v.size()-1 ? "\n" : " ");
    }
	return oss.str();
}


vector<string> generate_sample_tests() {
	vector<string> tests;
    vector<int> v = {1,2,3,4,5};
    tests.push_back(output_tc(v));
    v = {5,4,3,2,1};
    tests.push_back(output_tc(v));
    v = {1};
    tests.push_back(output_tc(v));
	return tests;
}


string rnd_test(int i){
    int max_n = MAX_N;
    int min_v = MIN_V;
    int max_v = MAX_V;
    
    if(i<rnd_test_n/3){
        max_n = 10;
        min_v = -5;
        max_v = 5;
    }
    else if(i<2*rnd_test_n/3){
        max_n = 100;
        min_v = -100;
        max_v = 100;
    }
    int n = rnd.next(1,max_n);
    vector<int> v;
    for(int i=0;i<n;i++){
        v.push_back(rnd.next(min_v,max_v));
    }
    return output_tc(v);
}

vector<string> generate_random_tests() { 
    vector<string> tests;
    for (int i = 0; i < rnd_test_n; i++){
        tests.push_back(rnd_test(i));
    } 
    return tests;
}

string extreme_test_1(){
    vector<int> v;
    for(int i=0;i<MAX_N;i++){
        v.push_back(MAX_V);
    }
    return output_tc(v);
}

string extreme_test_2(){
    vector<int> v;
    for(int i=0;i<MAX_N;i++){
        v.push_back(MIN_V);
    }
    return output_tc(v);
}

vector<string> generate_extreme_tests(){
    vector<string> tests;   
    tests.push_back(extreme_test_1());
    tests.push_back(extreme_test_2());
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