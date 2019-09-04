#include <bits/stdc++.h>

using namespace std;


int main(){
   map<int,int> mp;
   int n;
   cin >> n;
   for(int i=0;i<n;i++){
      int value;
      cin >> value;
      if(mp.find(value)==mp.end()){
         mp[value] = 1;
      }
      else{
         mp[value]++;
      }
   }
   for(auto k: mp){
      cout << k.first << " " << k.second << endl;
   }
   return 0;
}