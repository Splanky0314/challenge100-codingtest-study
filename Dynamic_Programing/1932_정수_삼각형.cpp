#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
int arr[501][501] = {};
ll dp[501][501] = {};

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<=i; j++) {
			cin >> arr[i][j];
		}
	}

	ll tmp1, tmp2;
	dp[0][0] = arr[0][0];
	for(int i=1; i<n; i++) {
		for(int j=0; j<=i; j++) {
			tmp1 = 0; tmp2 = 0;
			if(j-1 >= 0) tmp1 = dp[i-1][j-1];
			if(j <= i-1) tmp2 = dp[i-1][j];

			dp[i][j] = max(tmp1, tmp2) + arr[i][j];
		}
	}

	ll maxval = -1;
	for(int j=0; j<n; j++) {
		if(maxval == -1 || maxval < dp[n-1][j]) {
			maxval = dp[n-1][j];
		}
	}

	cout << maxval;
}