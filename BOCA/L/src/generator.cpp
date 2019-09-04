#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

const int MIN_N = 1;
const int MAX_N = 1000;

const int MIN_M = 0;
const int MAX_M = 1e7;

const int rnd_test_n = 100;

template <typename T> void append(vector<T> &dest, const vector<T> &orig) {
	dest.insert(dest.end(), orig.begin(), orig.end());
}

string output_tc(vector<int>& v) {
	ostringstream oss;
    oss << v.size() << endl;
    for(size_t i=0;i<v.size();i++){
        oss << v[i];
        if(i < v.size()-1) oss << " ";
    }
    oss << endl;
	return oss.str();
}


vector<string> generate_sample_tests() {
	vector<string> tests;
    vector<int> v =  {24,679};
    tests.push_back(output_tc(v));
	return tests;
}




string rnd_test(int i){
    int min_n = MIN_N;
    int max_n = MAX_N;

    int min_m = MIN_M; 
    int max_m = MAX_M;
    
    if(i<rnd_test_n/3){
        max_n = 5;
        max_m = 100;
    }
    else if(i<rnd_test_n/2){
        max_n = 50;
        max_m = 1000;
    }

    int n = rnd.next(min_n,max_n);
    vector<int>v (n);
    for(int i=0;i<n;i++){
        v[i] = rnd.next(min_m,max_m);
    }
    return(output_tc(v));
}

vector<string> generate_random_tests() { 
    vector<string> tests;
    for (int i = 0; i < rnd_test_n; i++){
        tests.push_back(rnd_test(i));
    } 
    return tests;
}

string extreme_test_1(){
    int n = MAX_N;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        v[i] = rnd.next(MIN_M,MAX_M);
    }
    return output_tc(v);

}

string extreme_test_2(){
    int n = MAX_N;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        v[i] = MAX_M;
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