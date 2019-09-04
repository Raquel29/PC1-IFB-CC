#include <bits/stdc++.h>

using namespace std;


int main(){
   double x;
   cin >> x;
   double sum = 0;
   double pot = x;
   double frac = 1;
   int sinal = 1;
   for(int i=1;i<=11;i++){
      sum += sinal * pot/frac;
      pot *= x*x;
      frac *= (2*i )*(2*i+1);
      sinal *=-1;
   }
   cout << sum << endl;
}