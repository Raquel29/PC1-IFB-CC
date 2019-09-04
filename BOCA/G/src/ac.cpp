#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool primo = true;
    if (n < 2) {
        primo = false;
    }
    if (n > 2 && n % 2 == 0) {
        primo = false;
    }
    for (size_t i = 3; i * i <= n; i+=2) {
        if (n % i == 0) {
            primo = false;
            break;
        }
    }
    if (primo) {
        cout << "Primo!" << endl;
    } else {
        cout << "Composto!" << endl;
    }
    return 0;
}