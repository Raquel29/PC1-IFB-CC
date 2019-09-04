#include <bits/stdc++.h>

using namespace std;

string s;

int extend(string &s, string &buffer, int pos, int i) {
    int c;
    for (c = 0; pos + c < (int)s.size() && i + c < (int)buffer.size() &&
                s[pos + c] == buffer[i + c];
         c++)
        ;
    return c;
}

void solve() {
    string buffer;
    int pos = 0;
    int op = 0;
    while (pos < (int)s.size()) {
        int max_extension = 0;
        for (size_t i = 0; i < buffer.size(); i++) {
            max_extension = max(max_extension, extend(s, buffer, pos, i));
        }
        if (max_extension == 0) {
            buffer += s[pos];
            pos++;
        } else {
            for (int i = pos; i < pos + max_extension; i++) {
                buffer += s[i];
            }
            pos += max_extension;
        }
        op++;
    }
    cout << op << endl;
}

int main() {
    cin >> s;
    solve();
    return 0;
}