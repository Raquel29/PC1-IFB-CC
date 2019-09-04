#include <bits/stdc++.h>

using namespace std;


void solve(int value){
   vector<int> v = {1,2,5,10,25,50,100};
   vector<int> qtd(7,0);
   int idx = v.size()-1;
   int moedas = 0;
   while(value){
      while(v[idx]>value) idx--;
      moedas += value/v[idx];
      qtd[idx] = value/v[idx];
      value = value % v[idx];
   }
   cout << moedas << " notas" << endl;
   for(int i=v.size()-1;i>=0;i--){
      cout << qtd[i] << " notas de " << v[i] << endl;
   }
}

int main(){
   int n;
   cin >> n;
   while(n--){
      int value;
      cin >> value;
      solve(value);
   }
   return 0;
}