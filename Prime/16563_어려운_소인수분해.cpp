#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 5000001

using namespace std;
using ll = long long;



int sieve[MAX]; // T: 합성수, F: 소수
vector<ll> prime;

void init_sieve() {
	sieve[1] = 1;
	for(ll i=2; i<MAX; i++) {
		if(sieve[i]) continue;
		prime.push_back(i);
		sieve[i] = i;
		for (ll j = i * i; j < MAX; j += i) {
			if(sieve[j] == 0) sieve[j] = i;
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 1/6 17:20

	ll n;
	vector<ll> k;
	cin >> n;
	k.resize(n+1);
	for(int i=0; i<n; i++) 
		cin >> k[i];

	init_sieve();
	// cout << prime.size() << endl; // for test
	// cout << prime[prime.size()-1] << endl;

	for(int T=0; T<n; T++) {
		ll target = k[T];
		ll pr;
		while(target > 1) {
			pr = sieve[target];
			cout << pr << " ";
			target /= pr;
		}

		// for(ll i=0; i<prime.size() && target > prime[i]; i++) {
		// 	if(target == 1) break;
		// 	if(sieve[target] != 0) {

		// 	}
		// 	while(target % prime[i] == 0) {
		// 		cout << prime[i] << " ";
		// 		target /= prime[i];

		// 	}
		// }
		if(target > 1) cout << target;
		cout << "\n";
	}
}