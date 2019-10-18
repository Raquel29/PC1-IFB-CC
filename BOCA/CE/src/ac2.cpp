#include <bits/stdc++.h>

using namespace std;

using vvi = vector<vector<int>>;

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

void solve(vvi& matrix){
   int n = matrix.size();
   int sum = numeric_limits<int>::min();
   int choice = n;
   for(int k=n-1;k>-n;k--){
      auto rv = sum_diagonal(matrix,k);
      if(rv > sum){
         sum = rv;
         choice = k;
      }
   }
   cout << choice << " " << sum << endl;
}

int main(){
   int n;
   cin >> n;
   vvi matrix(n,vector<int>(n));
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         cin >> matrix[i][j];
      }
   }
   solve(matrix);
   return 0;
}