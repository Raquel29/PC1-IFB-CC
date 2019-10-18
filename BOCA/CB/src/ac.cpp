#include <bits/stdc++.h>

using namespace std;

using vvd = vector<vector<double>>;
using vd = vector<double>;

vvd transpose_matrix(vvd &A) {
    vvd B(A[0].size(), vd(A.size()));
	for(size_t i=0;i<A.size();i++){
		for(size_t j=0;j<A[0].size();j++){
			B[j][i] = A[i][j];
		}
	}
    return B;
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
    int n, m;
    cin >> n >> m;
    auto A = read_matrix(n, m);
    auto B = transpose_matrix(A);
	print(B);
    return 0;
}