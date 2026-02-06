#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

static int t, k, n;
int dp[15][15];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	for(int T=0; T<t; T++) {
		cin >> k >> n;
		
		// init
		for(int i=0; i<=k; i++) {
			for(int j=0; j<=n; j++) {
				if(j == 1) dp[i][j] = 1;
				else if(i == 0) dp[i][j] = j;
				else dp[i][j] = 0; // init!
			}
		}

		ll sum = 0;
		for(int i=1; i<=k; i++) { // 1층부터
			sum = 0;
			for(int j=1; j<=n; j++) { // j호
				sum += dp[i-1][j];
				dp[i][j] = sum;
			}
		}

		// // for test;
		// for(int i=0; i<=k; i++) { // 1층부터
		// 	for(int j=1; j<=n; j++) { // j호
		// 		cout << dp[i][j] << " ";
		// 	} cout << endl;
		// }

		cout << dp[k][n] << "\n";
	}	
}