#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;
using vd = vector<double>;
using vvd = vector<vector<double>>;

double EPS = 1e-2;

vvd transpose_matrix(vvd &A) {
    vvd B(A[0].size(), vd(A.size()));
	for(size_t i=0;i<A.size();i++){
		for(size_t j=0;j<A[0].size();j++){
			B[j][i] = A[i][j];
		}
	}
    return B;
}

vvd read_matrix(int l, int c, InStream &stream) {
    vvd m(l, vd(c));
    for (size_t i = 0; i < l; i++) {
        for (size_t j = 0; j < c; j++) {
            m[i][j] = stream.readDouble();
        }
    }
    stream.readEoln();
    stream.readEof();
    return m;
}


void check_ans(vvd &A, InStream &stream) {
    auto B =   transpose_matrix(A);
    auto B_out = read_matrix(A[0].size(),A.size(),stream);
    for (size_t i = 0; i < B.size(); i++) {
        for (size_t j = 0; j < B[0].size(); j++) {
            ensuref(doubleCompare(B[i][j], B_out[i][j], EPS),
                    "C[%d][%d] == %lf != C_out[%d][%d] = %lf ", i, j, B[i][j],
                    i, j, B_out[i][j]);
        }
    }
}
int main(int argc, char *argv[]) {
    setName("Check matriz product");
    registerTestlibCmd(argc, argv);
    int n, m;
    n = inf.readInt();
    m = inf.readInt();
    auto A = read_matrix(n, m, inf);
    check_ans(A, ans);
    check_ans(A,ouf);
    quitf(_ok,"AC");
    return 0;
}

