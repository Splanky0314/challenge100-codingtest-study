#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int t, n;
int arr[2][100005];
int dp[2][100005];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tmp1, tmp2;

	cin >> t;
	for(int T=0; T<t; T++) {
		cin >> n;

		// initialize dp[][]
		for(int i=0; i<2; i++) 
			for(int j=0; j<n; j++) 
				dp[i][j] = 0;

		for(int i=0; i<n; i++) cin >> arr[0][i];
		for(int i=0; i<n; i++) cin >> arr[1][i];

		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		for(int i=0; i<n-1; i++) {
			for(int j=0; j<2; j++) {
				tmp1 = dp[j][i] + arr[(j+1)%2][i+1];
				tmp2 = dp[j][i] + arr[(j+1)%2][i+2];
				if(tmp1 > dp[(j+1)%2][i+1])
					dp[(j+1)%2][i+1] = tmp1;
				if(tmp2 > dp[(j+1)%2][i+2])
					dp[(j+1)%2][i+2] = tmp2;
			}
		}

		int maxval = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<2; j++) {
				if(maxval < dp[j][i]) maxval = dp[j][i];
			}
		}

		// // for test
		// for(int j=0; j<2; j++) {
		// 	for(int i=0; i<n; i++) {
		// 		cout << dp[j][i] << " ";
		// 	} cout << endl;
		// } cout << endl;

		cout << maxval << "\n";	
	}
}