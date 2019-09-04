#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

const int MIN_N = 1;
const int MAX_N = 1e5;

const int MIN_VALUE = -1000;
const int MAX_VALUE = 1000;

const int rnd_test_n = 100;

template <typename T> void append(vector<T> &dest, const vector<T> &orig) {
	dest.insert(dest.end(), orig.begin(), orig.end());
}

vector<double> generate_random_array(int n,double min_value,double max_value){
    vector<double> v;
    for(int i=0;i<n;i++)
        v.push_back(rnd.next(min_value,max_value));
    return v;
}

string output_tc(vector<double>& a, vector<double>& b) {
	ostringstream oss;
    oss << a.size() << endl;
    for(size_t i=0;i<a.size();i++){
        oss << a[i];
        oss << (i<a.size()-1 ? " " : "\n");
    }
    for(size_t i=0;i<b.size();i++){
        oss << b[i];
        oss << (i<a.size()-1 ? " " : "\n");
    }
	return oss.str();
}


vector<string> generate_sample_tests() {
	vector<string> tests;
    vector<double> a,b;
    a = {1,2,3};
    b = {3,2,1};
    tests.push_back(output_tc(a,b));
    a = {10,5.5,0};
    b = {2.5,0,3.3};
    tests.push_back(output_tc(a,b));
    a = {1.5,2.3,4.4};
    b = {9.8,8.7,7.6};
    tests.push_back(output_tc(a,b));
	return tests;
}



string rnd_test(int i){
    int min_n = MIN_N;
    int max_n = MAX_N;
    int min_value = MIN_VALUE;
    int max_value = MAX_VALUE;
    if(i<rnd_test_n/3){
        max_n = 10;
        min_value = -10;
        max_value = 10;
    }
    else if(i<rnd_test_n/2){
        max_n = 100;
        min_value = -100;
        max_value = 100;
    }

    int n = rnd.next(MIN_N,MAX_N);
    auto a = generate_random_array(n,min_value,max_value);
    auto b = generate_random_array(n,min_value,max_value);
    return(output_tc(a,b));
}

vector<string> generate_random_tests() { 
    vector<string> tests;
    for (int i = 0; i < rnd_test_n; i++){
        tests.push_back(rnd_test(i));
    } 
    return tests;
}

string extreme_test_1(){
    auto a = generate_random_array(MAX_N,MIN_VALUE,MIN_VALUE);
    auto b = generate_random_array(MAX_N,MIN_VALUE,MIN_VALUE);
    return output_tc(a,b);
}

string extreme_test_2(){
    auto a = generate_random_array(MAX_N,MAX_VALUE,MAX_VALUE);
    auto b = generate_random_array(MAX_N,MAX_VALUE,MAX_VALUE);
    return output_tc(a,b);
}

string extreme_test_3(){
    auto a = generate_random_array(MAX_N,0,0);
    auto b = generate_random_array(MAX_N,0,0);
    return output_tc(a,b);
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