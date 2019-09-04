#include "testlib.h"
#include <bits/stdc++.h>


using namespace std;

int n;
map<int,int> mp;

int check_ans(InStream& stream){
    int count = 0;
    while(!stream.seekEof()){
        count++;
        int occ, n_occ;
        occ = stream.readInt();
        n_occ = stream.readInt();
        ensuref(mp.find(occ)!=mp.end(),"%d is not present on input",occ);
        ensuref(mp[occ] == n_occ,"%d does not equal number of occurrences on input",n_occ);
    }
    ensuref(mp.size()==count,"number of printed elements does not correspond to optimal solution.\n");
    return 1;
}

int main(int argc, char* argv[]) {
    setName("Set the name of your checker here");
    registerTestlibCmd(argc, argv);
    n = inf.readInt();
    for(int i=0;i<n;i++){
        int value;
        value = inf.readInt();
        if(mp.find(value)==mp.end()){
            mp[value] = 1;
        }
        else{
            mp[value]++;
        }
    }
    int jans = check_ans(ans);
    int pans = check_ans(ouf);
    if(jans == pans){
        quitf(_ok,"Okay!");
    }
    else if(jans > pans){
        quitf(_wa,"Participant does not hold optimal solution");
    }
    quitf(_fail,"Judge is not correct.\n");
    return 0;
}