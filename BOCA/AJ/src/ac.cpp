#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " = " << x << endl;
const int MAX = 1e7 + 100;

bool primes[MAX];
void sieve()
{
	memset(primes, 1, sizeof primes);
	primes[0] = primes[1] = 0;
	for(int i = 2; i < MAX; i++)
		if(primes[i])
			for(int j = 2 * i; j < MAX; j += i)
				primes[j] = false;
}

bool ok(int x)
{
	for(; x; x /= 10)
		if(!primes[x])
			return false;
	return true;
}

int main()
{
	// time_t start = clock();

	sieve();
	// debug((double) (clock() - start) / CLOCKS_PER_SEC);

	int t;
	scanf("%d", &t);
	while(t--) {
		int x;
		scanf("%d", &x);
		printf("%c\n", ok(x) ? 'S' : 'N');
	}

	// debug((double) (clock() - start) / CLOCKS_PER_SEC);
	return 0;
}
