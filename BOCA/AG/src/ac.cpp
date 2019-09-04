#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> v(n);
    double media = 0;
    double maior, menor;
    int i_maior, i_menor;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i == 0) {
            maior = v[i];
            menor = v[i];
            i_maior = 0;
            i_menor = 0;
        } else {
            if (v[i] > maior) {
                i_maior = i;
                maior = v[i];
            } else if (v[i] < menor) {
                i_menor = i;
                menor = v[i];
            }
        }
        media += v[i];
    }
    media /= v.size();
    cout << i_menor << " " << setprecision(1) << fixed << menor << endl;
    cout << i_maior << " " << setprecision(1) << fixed << maior << endl;
    cout << setprecision(1) << fixed << media << endl;
    int count = 0;
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] >= media) {
            count++;
        }
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i] >= media) {
            cout << i;
            count--;
            cout << (count ? " " : "\n");
        }
    }
    return 0;
}