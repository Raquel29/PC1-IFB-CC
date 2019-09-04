#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    size_t number = 0;
    for (size_t i = 0; i < s.size(); i++) {
        number <<= 4;
        if (s[i] >= '0' && s[i] <= '9') {
            number += s[i] - '0';
        }else {
            number += s[i] - 'a' + 10;
        }
    }
    cout << number << endl;
    return 0;
}