#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n, k;
int dp[1001][1001];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for(int i=0; i<=n; i++) {
		dp[i][0] = 1;
		dp[i][1] = i; // 
		dp[i][i] = 1;
	}

	for(int i=2; i<=n; i++) {
		for(int j=1; j<i; j++) {
			dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % 10007;
		}
	}

	cout << dp[n][k];
}