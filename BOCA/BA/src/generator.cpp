#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

const int MIN_N = 1;
const int MAX_N  = 80;

const int rnd_test_n = 100;

template <typename T> void append(vector<T> &dest, const vector<T> &orig) {
	dest.insert(dest.end(), orig.begin(), orig.end());
}

string output_tc(string& s) {
	ostringstream oss;
    oss << s << endl;
	return oss.str();
}

string generate_palindrome(int n){
    string s;
    s.resize(n);
    for(int i=0;i<n/2;i++){
        s[i] = rnd.next("[a-zA-Z]")[0];
        s[s.size()-i-1] = s[i];        
    }
    if(n%2==1){
        s[n/2] = rnd.next("[a-zA-Z]")[0];
    }
    return s;
}

string generate_random_string(int n){
    string s;
    s.resize(n);
    pattern p = ("[a-zA-Z]{"+to_string(n)+","+to_string(n)+"}");
    s = p.next(rnd);
    return s;
}


vector<string> generate_sample_tests() {
	vector<string> tests;
    string s;
    s = "ovo";
    tests.push_back(output_tc(s));
    s = "kayak";
    tests.push_back(output_tc(s));
    s = "abracadabra";
    tests.push_back(output_tc(s));
	return tests;
}



vector<string> generate_manual_tests() {
	vector<string> tests;
    string s;
    s = "ele";
    tests.push_back(output_tc(s));
    s = "ela";
    tests.push_back(output_tc(s));
    s = "A";
    tests.push_back(output_tc(s));
	return tests;
}

string rnd_test(int i){
    int min_n = MIN_N;
    int max_n = MAX_N;
    
    if(i<rnd_test_n/3){
        max_n = 5;
    }
    else if(i<rnd_test_n/2){
        max_n = 20;
    }

    int n = rnd.next(min_n,max_n);
    bool coin = rnd.next(0,1);
    string s = coin ? generate_palindrome(n) : generate_random_string(n);
    return output_tc(s);
}

vector<string> generate_random_tests() { 
    vector<string> tests;
    for (int i = 0; i < rnd_test_n; i++){
        tests.push_back(rnd_test(i));
    } 
    return tests;
}

string extreme_test_1(){
    string s = generate_palindrome(MAX_N);
    return(output_tc(s));
}

string extreme_test_2(){
    string s = generate_random_string(MAX_N);
    return(output_tc(s));
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
	append(tests, generate_manual_tests());
	append(tests, generate_random_tests());
	append(tests, generate_extreme_tests());
	for (const auto &t : tests) {
		startTest(++test);
		cout << t;
	}
	return 0;
}