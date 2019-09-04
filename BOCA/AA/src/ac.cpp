#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
vector<bool> prime;

const int MIN_VALUE = 1;
const int MAX_VALUE = 1e7;

void erastostenes(size_t n) {
    prime.assign(n + 1, true);
    prime[0] = prime[1] = false;

    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}


int main(){
   int n;
   erastostenes(MAX_VALUE);
   cin >> n;
   while(n--){
      int value;
      cin >> value;
      cout << (prime[value] ? "primo\n" : "composto\n");
   }
   return 0;
}