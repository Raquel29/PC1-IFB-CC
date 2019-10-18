#include <bits/stdc++.h>

using namespace std;


string rle(string& s){
    string s2;
    int count = 0;
    size_t i;
    for(i=0;i<s.size();i++){
        if(i==0 || s[i]==s[i-1]){
            count++;
        }
        else{
            s2+=to_string(count)+s[i-1];
            count = 1;
        }
    }
    s2+=to_string(count)+s[i-1];
    return s2;
}
void solve(int n){
    string s = "1";
    // cout << s;
    for(int i=1;i<n;i++){
        string new_s = rle(s);
        swap(s,new_s);
        // cout << " " << s;
    }
    cout << s <<  endl;
}
int main(){
    int n;
    cin >> n;
    solve(n);
    return 0;
}