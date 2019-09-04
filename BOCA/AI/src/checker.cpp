#include "testlib.h"
#include <bits/stdc++.h>


using namespace std;


const int MIN_N = 0;
const int MAX_N = 5;

const double MIN_C = -10.0;
const double MAX_C = 10.0;

const int MIN_Q = 1;
const int MAX_Q = 1e5;

const double MIN_VALUE = -1e2;
const double MAX_VALUE = 1e2;



const double EPS = 1e-3;

vector<double> read_x(){
    int n = inf.readInt();
    inf.readDoubles(n+1,MIN_C,MAX_C);
    int q = inf.readInt();
    vector<double> x;
    for(int i=0;i<q;i++){
        x.push_back(inf.readDouble());
    }
    return x;
}

vector<double> read_ans(InStream& stream,vector<double>& x){
    vector<double> ans;
    for(size_t i=0;i<x.size();i++){
        double value = stream.readDouble();
        ans.push_back(value);
    }
    return ans;
}

int main(int argc, char* argv[]) {
    setName("Compare values of polynomials");
    registerTestlibCmd(argc, argv);
    vector<double> x = read_x();
    vector<double> jans = read_ans(ans,x);
    vector<double> pans = read_ans(ouf,x);
    for(size_t i=0;i<pans.size();i++){
        if(!doubleCompare(jans[i],pans[i],EPS)){
            quitf(_wa,"Pans differs more then EPS");
        }
    }
    quitf(_ok,"Okay!");
    return 0;
}