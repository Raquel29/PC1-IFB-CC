#include <bits/stdc++.h>

using namespace std;


class solver{
public:
    void read_input(){
        cin >> n;
        m = vector<vector<int>>(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> m[i][j];
            }
        }
    }
    void solve(){
        bool has_celeb = false;
        int celeb;
        for(int i=0;i<n && !has_celeb;i++){
            bool is_celeb = m[i][i];
            for(int j=0;j<n && is_celeb;j++){
                if(i!=j && m[i][j]){
                    is_celeb = false;
                }
            }
            for(int j=0;j<n && is_celeb;j++){
                if(i!=j && !m[j][i]){
                    is_celeb = false;
                }
            }
            if(is_celeb){
                celeb = i;
                has_celeb = true;
            }
        }
        if(has_celeb){
            cout << "Popstar: aluno #" << celeb+1 << endl; 
        }
        else{
            cout << "Nao ha popstar.\n";
        }
    }
public:
    int n;
    vector<vector<int>> m;
};


int main() {
    std::ios::sync_with_stdio(false); 
    solver s;    
    s.read_input();
    s.solve();
    return 0;
}