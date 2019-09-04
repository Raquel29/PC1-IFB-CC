#include <bits/stdc++.h>

using namespace std;

vector<size_t> find_occ(const string &text, std::string pattern) {

    vector<size_t> v;
    // Get the first occurrence
    size_t pos = text.find(pattern);

    // Repeat till end is reached
    while (pos != std::string::npos) {
        // Add position to the vector
        v.push_back(pos);
        // Get the next occurrence from the current position
        pos = text.find(pattern, pos + 1);
    }
    return v;
}

int main() {
    string t, p;
    getline(cin, t);
    getline(cin, p);
    auto v = find_occ(t, p);
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        cout << (i < v.size() - 1 ? " " : "\n");
    }
    return 0;
}