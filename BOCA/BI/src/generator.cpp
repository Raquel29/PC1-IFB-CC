#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

const int MIN_N = 1;
const int MAX_N = 1000;

const int rnd_test_n = 100;
const int extreme_test_n = 20;

template <typename T> void append(vector<T> &dest, const vector<T> &orig) {
	dest.insert(dest.end(), orig.begin(), orig.end());
}

string output_tc(const string& x) {
	ostringstream oss;
    oss << x << endl;
	return oss.str();
}


vector<string> generate_sample_tests() {
	vector<string> tests;
    string s = "abcdef";
    tests.push_back(output_tc(s));
    s = "aaaaaaaa";
    tests.push_back(output_tc(s));
    s = "abracadabra";
    tests.push_back(output_tc(s)); 
	return tests;
}



vector<string> generate_manual_tests() {
	vector<string> tests;
	string s = "mamaemandou";
    tests.push_back(output_tc(s));
    s = "mississippi";
    tests.push_back(output_tc(s));
	return tests;
}

string rnd_test(int i){
    int min_n = MIN_N;
    int max_n = MAX_N;
    
    if(i<rnd_test_n/3){
        max_n = 10;
    }
    else if(i<rnd_test_n/2){
        max_n = 100;
    }

    int sz = rnd.next(MIN_N,max_n);
    pattern p("[a-z]{" + to_string(max_n)+","+to_string(max_n)+"}");
    string s = p.next(rnd);
    return output_tc(s);
}

vector<string> generate_random_tests() { 
    vector<string> tests;
    for (int i = 0; i < rnd_test_n; i++){
        tests.push_back(rnd_test(i));
    } 
    return tests;
}

string extreme_test(){
    string s = rnd.next("[a-z]{1000,1000}");
    return(output_tc(s));
}

string extreme_test_2(){
    string s = rnd.next("[a]{1000,1000}");
    return(output_tc(s));
}

string extreme_test_3(){
    string s = rnd.next("[ab]{1000,1000}");
    return(output_tc(s));
}

string extreme_test_4(){
    string s = rnd.next("[a-z]{5,100}");
    string s2;
    while(s2.size() + s.size()<=1000){
        s2 += s;
    }
    return(output_tc(s2));
}


vector<string> generate_extreme_tests(){
    vector<string> tests;   
    for(int i=0;i<extreme_test_n;i++){
        tests.push_back(extreme_test());
    }
    tests.push_back(extreme_test_2());
    tests.push_back(extreme_test_3());
    for(int i=0;i<extreme_test_n;i++){
        tests.push_back(extreme_test_4());
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
	append(tests, generate_extreme_tests());
	for (const auto &t : tests) {
		startTest(++test);
		cout << t;
	}
	return 0;
}