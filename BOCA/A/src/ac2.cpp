#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    vector<int> v;
    cin >> n;
    while(n--){
        int aux;
        cin >> aux;
        v.push_back(aux);
    }
    sort(v.begin(),v.end());
    if(v.size()==1){
        cout << v[0] << endl << "nao definido" << endl << v[0] << endl << "nao definido" << endl;
    }
    else{
        cout << v[v.size()-1] << endl << v[v.size()-2] << endl << v[0] << endl << v[1] << endl ;
    }
    return 0;
}