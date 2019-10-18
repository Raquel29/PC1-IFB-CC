#include <bits/stdc++.h>

using namespace std;

const int MAX { 32 };

string seq[MAX];

void solve(int N)
{
    cout << seq[N];
}

void precomp()
{
    seq[0] = "\n";
    seq[1] = "1\n";

    for (int i = 2; i < MAX; ++i)
    {
        ostringstream os;

        char symbol { seq[i - 1][0] };
        int count = 1;

        for (size_t j = 1; j < seq[i - 1].size(); ++j)
        {
            if (seq[i - 1][j] == symbol)
                ++count;
            else
            {
                os << count << (char) symbol;
                symbol = seq[i - 1][j];
                count = 1;
            }
        }

        os << '\n';
        seq[i] = os.str();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    precomp();

    int N;
    cin >> N;

    cout << seq[N];

    return 0;
}
