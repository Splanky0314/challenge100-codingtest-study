#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
int arr[10001] = {};
int dp[10001][3] = {};

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i=0; i<n; i++)
		cin >> arr[i];

	dp[0][1] = arr[0];
	for(int i=1; i<n; i++) {
		dp[i][0] = max(max(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
		dp[i][1] = dp[i-1][0] + arr[i];
		dp[i][2] = dp[i-1][1] + arr[i]; 
	}

	cout << max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
}