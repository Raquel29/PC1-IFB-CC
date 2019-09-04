#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

const int MAX_N = 1e5;
const int MIN_N = 1;
const int MIN_V = 0;
const int MAX_V = 46;

const int rnd_test_n = 100;

template <typename T> void append(vector<T> &dest, const vector<T> &orig) {
	dest.insert(dest.end(), orig.begin(), orig.end());
}

string output_tc(vector<pair<int,int>>& p) {
	ostringstream oss;
    oss << p.size() << endl;
    for(auto pv: p){
        oss << pv.first << " " << pv.second << endl;
    }
	return oss.str();
}


vector<string> generate_sample_tests() {
	vector<string> tests;
    vector<pair<int,int>> pv = {{0,0},{2,5},{10,15}};
    tests.push_back(output_tc(pv));
	return tests;
}

vector<string> generate_complete_tests() {
    vector<string> tests;
    vector<pair<int,int>> pairs;
    for(int i=MIN_V;i<=MAX_V;i++){
        for(int j=i;j<=MAX_V;j++){
            pairs.push_back({i,j});
        }
    }
    tests.push_back(output_tc(pairs));
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