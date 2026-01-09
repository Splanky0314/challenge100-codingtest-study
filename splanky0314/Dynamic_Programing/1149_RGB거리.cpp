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
	int cost[1001][3];
	ll dp[1001][3] = {};

	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<3; j++) {
			cin >> cost[i][j];
		}
	}

	// initial value
	dp[0][0] = cost[0][0];
	dp[0][1] = cost[0][1];
	dp[0][2] = cost[0][2];

	ll tmp1, tmp2;
	for(int i=1; i<n; i++) {
		for(int j=0; j<3; j++) {
			tmp1 = dp[i-1][(j+1)%3] + cost[i][j];
			tmp2 = dp[i-1][(j+2)%3] + cost[i][j];
			if(tmp1 < tmp2) {
				dp[i][j] = tmp1;
			}
			else {
				dp[i][j] = tmp2;
			}
		}
	}

	ll minval = -1;
	for(int j=0; j<3; j++) {
		if(minval == -1 || minval > dp[n-1][j]) {
			minval = dp[n-1][j];
		}
	}
	cout << minval;
}