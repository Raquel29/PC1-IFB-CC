#include <bits/stdc++.h>

using namespace std;

double evaluate(vector<double> &coef, double x) {
    double sum = 0;
    double pot = 1;
    for (auto c : coef) {
        sum += c * pot;
        pot *= x;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<double> coef;
    for (int i = 0; i <= n; i++) {
        double value;
        cin >> value;
        coef.push_back(value);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        double x;
        cin >> x;
        cout << evaluate(coef, x) << endl;
    }
    return 0;
}