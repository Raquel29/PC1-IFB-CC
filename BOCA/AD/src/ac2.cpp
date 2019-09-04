#include <bits/stdc++.h>

using namespace std;

vector<double> x, y;
int n;

double euclidean_distance(int i, int j) {
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

void solve() {
    double dist = numeric_limits<double>::max();
    int a, b;
    for (int i = n-1; i >=0 ; i--) {
        for (int j = i-1; j >=0; j--) {
            double d = euclidean_distance(i, j);
            if (d < dist) {
                a = i;
                b = j;
                dist = d;
            }
        }
    }
    cout << "Pontos: " << a << " e " << b << endl;
    cout << "Distancia: " << dist << endl;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        double value;
        cin >> value;
        x.push_back(value);
    }
    for (int i = 0; i < n; i++) {
        double value;
        cin >> value;
        y.push_back(value);
    }
    solve();
    return 0;
}