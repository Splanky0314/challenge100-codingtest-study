#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	char arr[1001][1001];
	vector<vector<int>> dp;

	cin >> n >> m;
	dp.resize(n+1, vector<int>(m+1));
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin >> arr[i][j];
		}
	}

	int maxval = 0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(arr[i][j] == '1') {
				if(dp[i-1][j] && dp[i][j-1] && dp[i-1][j-1]) {
					dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
				}
				else dp[i][j] = 1;

				if(maxval < dp[i][j])
					maxval = dp[i][j];
			}
			else dp[i][j] = 0;
		}
	}

	// // for test
	// for(int i=1; i<=n; i++) {
	// 	for(int j=1; j<=m; j++) {
	// 		cout << dp[i][j] << " ";
	// 	} cout << endl;
	// } cout << endl;

	cout << maxval * maxval;
}