#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, s, e;
	int arr[2001] = {};
	int dp[4002] = {};
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i]; 
	

	// init dp
	for(int i=0; i<n*2-1; i++) {
		int j = 1;
		while(0<=((i+1)/2-j) && (i/2+j)<n) {
			if(arr[(i+1)/2-j] != arr[i/2+j]) {
				break;
			}
			else {
				dp[i]++;
			}
			j++;
		}
	}

	// // for test
	// for(int i=0; i<n*2-1; i++) {
	// 	cout << dp[i] << " ";
	// } cout << endl;

	cin >> m;
	for(int i=0; i<m; i++) {
		cin >> s >> e; s--; e--;

		int mid = s + e;
		if(dp[mid] >= (e-s+1)/2) cout << 1 << "\n";
		else cout << 0 << "\n";
	} 
}