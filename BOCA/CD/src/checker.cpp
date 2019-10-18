#include "testlib.h"
#include <string>
#include <vector>

using namespace std;

void validate_solution(int N, int M, const vector<string> &A,
                       InStream &in) {
    auto x = in.readInt(1, N, "x");
    in.readSpace();
    auto y = in.readInt(1, M, "y");

    if (A[x - 1][y - 1] != 'W')
        quitf(_wa, "Waldo is not in x = %d, y = %d", x, y);
}

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    auto N = inf.readInt();
    auto M = inf.readInt();
    inf.readEoln();

    vector<string> A(N);

    for (int i = 0; i < N; ++i) {
        A[i] = inf.readToken();
        inf.readEoln();
    }

    validate_solution(N, M, A, ouf);
    validate_solution(N, M, A, ans);

    quitf(_ok, "The solution is correct.");
}
