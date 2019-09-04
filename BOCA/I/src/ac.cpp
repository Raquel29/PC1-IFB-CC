#include <bits/stdc++.h>

using namespace std;


int main(){
   double r;
   int n;
   double m;
   double initial_m;
   cin >> m >> n >> r;
   initial_m = m;
   for(int i=1;i<=n;i++){     
      m = m*(1.0+r/100.0);
   }
   cout << setprecision(2) << fixed << m << endl;
   return 0;
}