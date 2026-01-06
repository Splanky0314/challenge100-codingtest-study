#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007

using namespace std;
using ll = long long;

vector<ll> twopow(300001);

void calcpow() {
	twopow[0] = 1;
	for(int i=1; i<300001; i++) {
		twopow[i] = twopow[i-1] * 2 % MOD;
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 1/6 13:32 ~ 17:12

	ll n, k;
	ll ans = 0, tmp;
	vector<ll> arr;
	
	cin >> n;
	arr.resize(n);
	for(int i=0; i<n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());

	calcpow();

	for(int i=0; i<n; i++) {
		// cout << "!!! " << arr[i] << endl;
		k = n-1-i;

		tmp = (twopow[i] - twopow[k] + MOD) % MOD;
		tmp = arr[i] * tmp % MOD;
		ans = (ans + tmp) % MOD;
	}

	cout << ans;
}