#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 9901

using namespace std;
using ll = long long;

int dp[100001];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	dp[1] = 3;
	dp[2] = 7;
	for(int i=3; i<=n; i++) {
		dp[i] = (dp[i-2] + (dp[i-1] * 2) % MOD) % MOD;
	}

	cout << dp[n];
}