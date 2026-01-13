#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 15746

using namespace std;
using ll = long long;

int n;
int dp[1000001];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;

	dp[1] = 1;
	dp[2] = 2;

	for(int i=3; i<=n; i++) {
		dp[i] = (dp[i-1] + dp[i-2]) % MOD;
	}

	cout << dp[n];
}