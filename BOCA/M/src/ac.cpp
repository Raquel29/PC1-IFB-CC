
#include <bits/stdc++.h>
using namespace std;

int a, b, c;

bool check(int x, int y, int z) {
    return (x != y && x != z && y != z && x + y + z == a && x * y * z == b &&
            x * x + y * y + z * z == c);
}

void solve() {
    bool ans = false;
    for (int x = -22; x <= 22 && !ans; x++)
        for (int y = -100; y <= 100 && !ans; y++)
            for (int z = -100; z <= 100 && !ans; z++)
                if (check(x, y, z)) {
                    vector<int> v({x, y, z});
                    sort(v.begin(), v.end());
                    cout << v[0] << " " << v[1] << " " << v[2] << endl;
                    ans = true;
                }
    if (!ans)
        cout << "Sem solucao\n";
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> a >> b >> c;
        solve();
    }
    return 0;
}