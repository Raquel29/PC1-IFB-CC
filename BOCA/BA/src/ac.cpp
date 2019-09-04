#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(string& s){
   for(size_t i=0;i<s.size()/2;i++){
      if(s[i]!=s[s.size()-i-1]){
         return false;
      }
   }
   return true;
}

int main(){
   string s;
   getline(cin,s);
   cout << (is_palindrome(s) ? "S" : "N") << endl;
   return 0;
}