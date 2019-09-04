#include <bits/stdc++.h>

using namespace std;

string cesar(string& line,int k){
   string s;
   for(auto c: line){
      s.push_back( ' ' + ( (c-' ' +k) % 95 ));
   }
   return s;
}


int main(){
   int n,k;
   cin >> n >> k;
   cin.ignore(1);
   while(n--){
      string line;
      getline(cin,line);
      cout << cesar(line,k) << endl;
   }
   return 0;
}