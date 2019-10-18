#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;
using vd = vector<double>;
using vvd = vector<vector<double>>;

double EPS = 1e-2;

vvd read_matrix(int l, int c, InStream &stream) {
    vvd m(l, vd(c));
    for (size_t i = 0; i < l; i++) {
        for (size_t j = 0; j < c; j++) {
            m[i][j] = stream.readDouble();
        }
    }
    return m;
}

vector<vector<double>> matrix_multiplication(vector<vector<double>> &A,
                                             vector<vector<double>> &B) {
    vector<vector<double>> C(A.size(), vector<double>(B[0].size(), 0.0));
    for (size_t i = 0; i < A.size(); i++) {
        for (size_t j = 0; j < B[0].size(); j++) {
            for (size_t k = 0; k < A[0].size(); k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

void check_ans(vvd &A, vvd &B, InStream &stream) {
    if (A[0].size() != B.size()) {
        stream.readToken("impossivel");
        stream.readEoln();
        stream.readEof();
        return;
    }
    auto C = matrix_multiplication(A, B);
    auto C_out = read_matrix(A.size(), B[0].size(), stream);
    for (size_t i = 0; i < C.size(); i++) {
        for (size_t j = 0; j < C[0].size(); j++) {
            ensuref(doubleCompare(C[i][j], C_out[i][j], EPS),
                    "C[%d][%d] == %lf != C_out[%d][%d] = %lf ", i, j, C[i][j],
                    i, j, C_out[i][j]);
        }
    }
}
int main(int argc, char *argv[]) {
    setName("Check matriz product");
    registerTestlibCmd(argc, argv);
    int n, m, k, l;
    n = inf.readInt();
    m = inf.readInt();
    k = inf.readInt();
    l = inf.readInt();
    auto A = read_matrix(n, m, inf);
    auto B = read_matrix(k, l, inf);
    check_ans(A, B, ans);
    check_ans(A, B, ouf);
    quitf(_ok,"AC");
    return 0;
}

