#include <iostream>

using namespace std;

#define MAX 26

int hist[MAX];

int main() {
    ios::sync_with_stdio(false);
    string w;
    getline(cin, w);

    for (auto c : w)
        ++hist[c - 'A'];

    int even = 0, odd = 0;

    for (int i = 0; i < MAX; ++i)
        hist[i] % 2 ? ++odd : ++even;

    printf("%s\n", (odd < 2 ? "Sim" : "Nao"));

    return 0;
}
