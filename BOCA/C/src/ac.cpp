#include <bits/stdc++.h>

using namespace std;


int main(){
   double pi = 0;
   const int MAX_IT = 1e7;
   for(int i=0;i<MAX_IT;i++){
      pi+= 2.0/((4*i+1) * (4*i+3));
   }
   cout << pi*4 << endl;
}