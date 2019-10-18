#include <bits/stdc++.h>

using namespace std;

using vvd = vector<vector<double>>;
using vd = vector<double>;

vvd matrix_multiplication(vvd &A, vvd &B) {
    vvd C(A.size(), vd(B[0].size(), 0.0));
    for (size_t i = 0; i < A.size(); i++) {
        for (size_t j = 0; j < B[0].size(); j++) {
            for (size_t k = 0; k < A[0].size(); k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

vvd read_matrix(int l, int c) {
    vvd m(l, vd(c));
    for (size_t i = 0; i < l; i++) {
        for (size_t j = 0; j < c; j++) {
            cin >> m[i][j];
        }
    }
    return m;
}

void print(vvd &C) {
    for (size_t i = 0; i < C.size(); i++) {
        for (size_t j = 0; j < C[i].size(); j++) {
            cout << setprecision(2) << fixed << C[i][j];
            cout << (j < C[i].size() - 1 ? " " : "\n");
        }
    }
}

int main() {
    int n, m, k, l;
    cin >> n >> m >> k >> l;
    auto A = read_matrix(n, m);
    auto B = read_matrix(k, l);
    if (m != k)
        cout << "impossivel\n";
    else {
        auto C = matrix_multiplication(A, B);
        print(C);
    }
    return 0;
}