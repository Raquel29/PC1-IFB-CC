#include <bits/stdc++.h>

using namespace std;

vector<double> valores;

void solve(){
   double media = 0;
   double stdev = 0;
   for(auto v: valores){
      media+= v;
   }
   media /= valores.size();
   for(auto v: valores){
      stdev += (v-media)*(v-media);
   }
   stdev /= valores.size();
   stdev = sqrt(stdev);
   cout << stdev << endl;
}


int main(){
   int n;
   cin >> n;
   valores.assign(n,0.0);
   for(int i=0;i<n;i++){
      cin >> valores[i];
   }
   solve();
   return 0;
}