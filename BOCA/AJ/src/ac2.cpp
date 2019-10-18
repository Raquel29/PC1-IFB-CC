#include <bits/stdc++.h>

using namespace std;

vector<bool> prime;
int t;
int n;

const int MAX = 10000001;

void sieve() {
    prime.assign(MAX, true);
    prime[0] = false;
    prime[1] = false;
    prime[2] = true;

    for(int j=4;j<MAX;j+=2){
        prime[j] = false;
    }
    for (int i = 3; i < sqrt(MAX); i += 2) {
        if (!prime[i])
            continue;
        for (int j = i * i; j < MAX; j += i) {
            prime[j] = false;
        }
    }
}

void solve() {
    bool ans = true;
    while (n) {
        if (!prime[n]) {
            ans = false;
            break;
        }
        n /= 10;
    }
    cout << (ans ? "S" : "N") << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    sieve();
    cin >> t;
    while (t--) {
        cin >> n;
        solve();
    }
    return 0;
}