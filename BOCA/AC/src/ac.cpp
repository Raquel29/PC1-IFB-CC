#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += a[i] * b[i];
    }
	cout << sum << endl;
    return 0;
}