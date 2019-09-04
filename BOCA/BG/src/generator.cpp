#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

const int MIN_N = 1;
const int MAX_N = 1e3;

const int MIN_R = 1;
const int MAX_R = 1e3;

const int rnd_test_n = 100;

template <typename T> void append(vector<T> &dest, const vector<T> &orig) {
	dest.insert(dest.end(), orig.begin(), orig.end());
}

string output_tc(string s) {
	ostringstream oss;
    oss << s << endl;
	return oss.str();
}


vector<string> generate_sample_tests() {
	vector<string> tests;
    tests.push_back(output_tc("a"));
    tests.push_back(output_tc("aaaaabbraaaaaaaaaccccccaaadaabrrrrra"));
    tests.push_back(output_tc("aaaaaaaa"));
	return tests;
}


string generate_string(int n,int max_rep_size){
    int i=0;
    string s;
    while(i<n){
        bool coin = rnd.next(0,1);
        char c = rnd.next("[a-z]")[0];
        if(coin){
            int rep = rnd.next(1,max_rep_size);
            for(int j=0;j<rep && i<n;i++,j++){
                s.push_back(c);
            }
        }
        else{
            s.push_back(c);
            i++;
        }
    }
    return s;
}

string rnd_test(int i){
    int min_n = MIN_N;
    int max_n = MAX_N;

    int min_r = MIN_R;
    int max_r = MAX_R;
    
    if(i<rnd_test_n/3){
        max_n = 20;
        max_r = 10;
    }
    else if(i<rnd_test_n/2){
        max_n = 100;
        max_r = 20;
    }

    int n = rnd.next(min_n,max_n);
    int max_rep_size = rnd.next(min_r,max_r);
    string s = generate_string(n,max_rep_size);
    return(output_tc(s));
}

vector<string> generate_random_tests() { 
    vector<string> tests;
    for (int i = 0; i < rnd_test_n; i++){
        tests.push_back(rnd_test(i));
    } 
    return tests;
}

string extreme_test_1(){
    return(output_tc(generate_string(MAX_N,100)));
}

string extreme_test_2(){
    string s;
    s.resize(MAX_N);
    fill(s.begin(),s.end(),'a');
    return output_tc(s);
}

string extreme_test_3(){
    string s;
    auto c = 'a';
    for(int i=0;i<MAX_N;i++){
        s.push_back(c);
        c++;
        if(c>'z'){
            c = 'a';
        }
    }
    return output_tc(s);
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