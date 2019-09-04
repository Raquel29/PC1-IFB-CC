#include <bits/stdc++.h>

using namespace std;


int main(){
   vector<int> v;
   int n;
   cin >> n;
   v.assign(n,0);
   for(int i=0;i<n;i++){
      cin >> v[i];
   }
   for(int i=n-1;i>=0;i--){
      cout << v[i];
      cout << ((i==0) ? "\n" : " ");
   }
   return 0;
}