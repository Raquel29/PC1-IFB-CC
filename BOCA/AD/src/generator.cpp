#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

const int MIN_N = 2;
const int MAX_N = 1000;

const double MIN_V = -1000;
const double MAX_V = 1000;

const int rnd_test_n = 100;

template <typename T> void append(vector<T> &dest, const vector<T> &orig) {
	dest.insert(dest.end(), orig.begin(), orig.end());
}

string output_tc(vector<double>& x,vector<double>& y) {
	ostringstream oss;
    oss << x.size() << endl;
    for(size_t i=0;i<x.size();i++){
        oss << fixed << setprecision(1) << x[i];
        oss << (i<x.size()-1 ? " " : "\n");
    }
    for(size_t i=0;i<y.size();i++){
        oss << fixed << setprecision(1) << y[i];
        oss << (i<x.size()-1 ? " " : "\n");
    }
	return oss.str();
}

vector<double> generate_random_array(int n,int min_v=MIN_V,int max_v=MAX_V){
    vector<double> v(n);
    for(int i=0;i<n;i++){
        v[i] = rnd.next(min_v,max_v);
    }
    return v;
}


vector<string> generate_sample_tests() {
	vector<string> tests;
    vector<double> a,b;
    a = {0.0,1.0,2.0};
    b = {0.0,1.0,2.0};
    tests.push_back(output_tc(a,b));
    a = {-2,2,2};
    b = {-2,-2,1};
    tests.push_back(output_tc(a,b));
    a = {-3,-1,-1,1,3};
    b = {-2,0,2,2,4};
    tests.push_back(output_tc(a,b));
	return tests;
}


string rnd_test(int i){
    int min_n = MIN_N;
    int max_n = MAX_N;
    double min_v = MIN_V;
    double max_v = MAX_V;
    
    if(i<rnd_test_n/3){
        max_n = 5;
        min_v = -5;
        max_v = -5;
    }
    else if(i<rnd_test_n/2){
        max_n = 20;
        min_v = -10;
        max_v = 10;
    }

    int n = rnd.next(min_n,max_n);
    auto x = generate_random_array(n,min_v,max_v);
    auto y = generate_random_array(n,min_v,max_v);
    return output_tc(x,y);
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
    auto x = generate_random_array(n,MIN_V,MIN_V);
    vector<double> y;
    for(int i=0;i<n;i++){
        y.push_back(i);
    }
    return output_tc(x,y);
}

string extreme_test_2(){
    int n = MAX_N;
    auto x = generate_random_array(n,MIN_V,MIN_V);
    vector<double> y;
    for(int i=0;i<n;i++){
        y.push_back(i);
    }
    return output_tc(y,x);
}

string extreme_test_3(){
    int n = MAX_N;
    auto x = generate_random_array(n,MAX_V,MAX_V);
    vector<double> y;
    for(int i=0;i<n;i++){
        y.push_back(i);
    }
    return output_tc(x,y);
}

string extreme_test_4(){
    int n = MAX_N;
    auto x = generate_random_array(n,MAX_V,MAX_V);
    vector<double> y;
    for(int i=0;i<n;i++){
        y.push_back(i);
    }
    return output_tc(y,x);
}

string extreme_test_5(){
    int n = MAX_N;
    auto x = generate_random_array(n);
    auto y = generate_random_array(n);
    return output_tc(y,x);
}

vector<string> generate_extreme_tests(){
    vector<string> tests;   
    tests.push_back(extreme_test_1());
    tests.push_back(extreme_test_2());
    tests.push_back(extreme_test_3());
    tests.push_back(extreme_test_4());
    tests.push_back(extreme_test_5());
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