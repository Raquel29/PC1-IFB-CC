#include <bits/stdc++.h>

using namespace std;

string rle_decode(string s) {
    size_t i = 0;
    ostringstream oss;
    while (i < s.size()) {
        int num = 0;
        while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
            num *= 10;
            num += s[i] - '0';
            i++;
        }
        if(num>0){
            for (int j = 0; j < num; j++) {
                oss << s[i];
            }
        }
        else{
            oss << s[i];
        }
        i++;
    }
    return oss.str();
}

int main() {
    string s;
    getline(cin, s);
    cout << rle_decode(s);
    return 0;
}