#include<iostream>
using namespace std;

#define debug(x) cerr << #x << " = " << x << endl;

bool isprime(int x)
{
	if(x <= 1)
		return false;
	if(x == 2)
		return true;
	if(x % 2 == 0)
		return false;

	for(int i = 3; 1ll * i * i <= x; i += 2)
		if(x % i == 0)
			return false;
	return true;
}

bool ok(int x)
{
	for(; x; x /= 10)
		if(!isprime(x))
			return false;
	return true;
}

int main()
{
	// time_t start = clock();
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
