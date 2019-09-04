#include <bits/stdc++.h>

using namespace std;

string rle_encode(string &s) {
    string s2;
    ostringstream oss;
    int count = 0;
    int i;
    for (i = 0; i < s.size(); i++) {
        if (i == 0 || s[i] == s[i - 1]) {
            count++;
        } else if (s[i] != s[i - 1]) {
            if (count > 1) {
                oss << count << s[i - 1];
            } else {
                oss << s[i - 1];
            }
            count = 1;
        }
    }
    if (count > 1) {
        oss << count << s[i - 1] << endl;
    } else {
        oss << s[i - 1] << endl;
    }
    return oss.str();
}
int main() {
    string s;
    getline(cin, s);
    cout << rle_encode(s) << endl;
    return 0;
}