#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	int dp[12][12];
	cin >> n >> k;

	for(int i=0; i<=n; i++) {
		for(int j=0; j<=n; j++) {
			if(i == j) dp[i][j] = 1;
			else if(j == 0) dp[i][j] = 1;
			else dp[i][j] = 0; // 초기화 잊지마라
		}
	}
	
	for(int i=2; i<=n; i++) {
		for(int j=1; j<i; j++) {
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
		}
	}

	// // for test
	// for(int i=0; i<=n; i++) {
	// 	for(int j=0; j<=10; j++) {
	// 		cout << dp[i][j] << " ";
	// 	} cout << endl;
	// }

	cout << dp[n][k];
}