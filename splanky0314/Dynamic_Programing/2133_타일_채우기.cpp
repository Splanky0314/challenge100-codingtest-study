#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	ll dp[16] = {};
	cin >> n;

	if(n%2) { // odd
		cout << 0; return 0;
	}
	n /= 2;

	dp[1] = 3;
	for(int i=2; i<=n; i++) {
		ll sum = dp[i-1] * dp[1];
		int j = 2;
		while(i-j >= 1) {
			sum += dp[i-j] * 2;
			j++;
		}
		dp[i] = sum + 2;
	}

	cout << dp[n];
}