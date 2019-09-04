#include <bits/stdc++.h>

using namespace std;

int main() {
    int maior, menor, seg_maior, seg_menor;
    bool seg_maior_def = false;
    bool seg_menor_def = false;
    int n;
    cin >> n;
    cin >> maior;
    menor = maior;
    for (int i = 1; i < n; i++) {
        int valor;
        cin >> valor;
        if (maior < valor) {
            seg_maior = maior;
            maior = valor;
            seg_maior_def = true;
        } else if (!seg_maior_def || seg_maior < valor) {
            seg_maior = valor;
            seg_maior_def = true;
        }

        if (menor > valor) {
            seg_menor = menor;
            menor = valor;
            seg_menor_def = true;
        } else if (!seg_menor_def || seg_menor > valor) {
            seg_menor = valor;
            seg_menor_def = true;
        }
    }
    cout << maior << endl;
    if (!seg_maior_def)
        cout << "nao definido" << endl;
    else
        cout << seg_maior << endl;

    cout << menor << endl;
    if (!seg_menor_def)
        cout << "nao definido" << endl;
    else
        cout << seg_menor << endl;
    return 0;
}