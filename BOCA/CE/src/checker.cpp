#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

using vvi = vector<vector<int>>;
using vi = vector<int>;

vvi read_matrix(int l, int c, InStream &stream) {
    vvi m(l, vi(c));
    for (size_t i = 0; i < l; i++) {
        for (size_t j = 0; j < c; j++) {
            m[i][j] = stream.readInt();
        }
    }
    return m;
}

int sum_diagonal(vvi& matrix, int k){
   int sum = 0;
   int i = (k<0) ? -k : 0;
   int j =i+k;
   while(i<matrix.size() && j<matrix.size()){
      sum+=matrix[i][j];
      i++;
      j++;
   }
   return sum;
}

int check_ans(vvi& m,InStream& stream){
    int ans,sum;
    ans = stream.readInt(-m.size()+1,m.size()-1,"diagonal");
    stream.readSpace();
    sum = stream.readInt();
    stream.readEoln();
    ensuref(sum_diagonal(m,ans)==sum,"Informed diagonal does not sum %d",sum);
    return sum;
}

int main(int argc, char *argv[]) {
    setName("compare files as sequence of tokens in lines");
    registerTestlibCmd(argc, argv);
    int n = inf.readInt();
    auto m = read_matrix(n,n,inf);
    int ans_j = check_ans(m,ans);
    int ans_p = check_ans(m,ouf);
    if(ans_j<ans_p){
        quitf(_fail,"Jury solution or checker are incorrect.");
    }
    else if(ans_j>ans_p){
        quitf(_wa,"Participant solution is not optimal");
    }
    quitf(_ok,"AC");
}