#include <bits/stdc++.h>

using namespace std;

const int MAX = 46;
vector<uint64_t> preprocess() {
    vector<uint64_t> v(MAX+2);
    v[0] = 0;
    v[1] = 1;
    v[2] = 1;
    for (int i = 3; i <= MAX+1; i++) {
        v[i] = v[i - 1] + v[i - 2];
    }
    for (int i = 1; i <= MAX+1; i++) {
        v[i] += v[i - 1];
    }
	return v;
}

int main() {
    int n;
    auto fib_sum = preprocess();
    cin >> n;
    while (n--) {
        int i, j;
        cin >> i >> j;
        i++;
        j++;
        cout << fib_sum[j] - fib_sum[i - 1] << endl;
    }
    return 0;
}