#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    int number = 0;
    for (size_t i = 0; i < s.size(); i++) {
        number <<= 1;
        number |= (s[i] == '0') ? 0 : 1;
    }
    cout << number << endl;
    return 0;
}