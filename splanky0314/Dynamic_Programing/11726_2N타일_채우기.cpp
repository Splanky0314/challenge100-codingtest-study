#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 10007

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	ll dp[1001];

	cin >> n;

	dp[1] = 1; dp[2] = 2;
	for(int i=3; i<=n; i++) {
		dp[i] = (dp[i-2] + dp[i-1]) % MOD;
	}

	cout << dp[n];
}