#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, s, max;
	int v[51];
	bool dp[52][1001] = {};
	
	cin >> n >> s >> max;
	for(int i=0; i<n; i++) cin >> v[i];

	dp[0][s] = true;
	for(int i=0; i<n; i++) {
		for(int j=0; j<=max; j++) {
			if(dp[i][j]) {
				if(j + v[i] <= max) {
					dp[i+1][j+v[i]] = true;
				}
				if(j - v[i] >= 0) {
					dp[i+1][j-v[i]] = true;
				}
			}
		}
	}

	for(int j=max; j>=0; j--) {
		if(dp[n][j]) {
			cout << j;
			return 0;
		}		
	}
	cout << -1;
}