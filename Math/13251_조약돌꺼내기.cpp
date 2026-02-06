#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int m, k;
int totalsum = 0;
int amount[51];
double ans = 0;
ll dp[2501][2501];
double possib[2501];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m;
	for(int i=0; i<m; i++) {
		cin >> amount[i];
		totalsum += amount[i];
	}
	cin >> k;

	for(int i=0; i<m; i++) {
		if(amount[i] >= k) {
			possib[i] = 1.0;
			for(int j=0; j<k; j++) {
				possib[i] *= double(amount[i] - j) / (totalsum - j);
			}
			ans += possib[i];
		}
	}

	// // init dp
	// for(int i=0; i<=totalsum; i++) {
	// 	dp[i][i] = 1;
	// 	dp[i][0] = 1;
	// 	dp[i][1] = i;
	// }

	// for(int i=2; i<=totalsum; i++) {
	// 	for(int j=1; j<i; j++) {
	// 		dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
	// 	}
	// }

	// // for test
	// for(int i=0; i<=totalsum; i++) {
	// 	for(int j=0; j<=k; j++) {
	// 		cout << dp[i][j] << " ";
	// 	} cout << endl;
	// } cout << endl << endl;

	// // overflow 발생!!
	// for(int i=0; i<m; i++) {
	// 	if(amount[i] >= k) {
	// 		ans += dp[amount[i]][k];
	// 	}
	// }

	cout << fixed;
	cout.precision(9);
	cout << ans;
}