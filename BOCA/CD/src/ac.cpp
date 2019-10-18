#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

ii solve(int N, int M, const vector<string>& A)
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (A[i][j] == 'W')
                return ii(i + 1, j + 1);
 
    return ii(0, 0);
}

int main()
{
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<string> A(N);

    for (int i = 0; i < N; ++i)
        cin >> A[i];

    auto pos = solve(N, M, A);

    cout << pos.first << ' ' << pos.second << '\n';

    return 0;
}

