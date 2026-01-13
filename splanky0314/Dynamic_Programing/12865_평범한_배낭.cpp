#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n, kg;
int w[101] = {}, v[202] = {};
int dp[101][100001] = {};

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	

	cin >> n >> kg;
	for(int i=0; i<n; i++) {
		cin >> w[i] >> v[i];
	}

	if(w[0] <= kg) dp[0][w[0]] = v[0];
	for(int i=1; i<n; i++) {
		if(w[i] <= kg) dp[i][w[i]] = v[i];
		for(int j=1; j<=kg; j++) {
			if(dp[i-1][j]) {
				if ((j+w[i])<=kg) {
					dp[i][j+w[i]] = dp[i-1][j] + v[i];
				}

				if(dp[i][j] < dp[i-1][j]) 
					dp[i][j] = dp[i-1][j];
			}
		}
	} 

	int maxval = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<=kg; j++) {
			if(maxval < dp[i][j])
				maxval = dp[i][j];
		}
	}

	// // for test
	// for(int i=0; i<n; i++) {
	// 	for(int j=0; j<=kg; j++) {
	// 		cout << dp[i][j] << " ";
	// 	} cout << endl;
	// } cout << endl;

	cout << maxval;
}