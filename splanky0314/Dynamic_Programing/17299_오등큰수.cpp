#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n; 
// vector<int> arr(1000001);
// vector<int> f(1000001);
// vector<int> dp(1000001);
// vector<int> ans(1000001);
int arr[1000001], f[1000001], dp[1000001], ans[1000001];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n; 
	// arr.resize(n); ans.resize(n); f.resize(n+1); dp.resize(n+1);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		f[arr[i]] += 1;
	}

	ans[n-1] = -1; dp[n-1] = -1;
	for(int i=n-2; i>=0; i--) {
		int idx = i+1;
		while(true) {
			// cout << i << " " << idx << endl;
			if(f[arr[i]] < f[arr[idx]]) {
				dp[i] = idx;
				ans[i] = arr[idx];
				break;
			}
			else if(dp[idx] == -1) {
				dp[i] = -1; ans[i] = -1; break;	
			}
			else idx = dp[idx];

			if(idx >= n) {
				dp[i] = -1; ans[i] = -1; break;
			}
		}
	}

	for(int i=0; i<n; i++) {
		cout << ans[i] << " ";
	} 
	// cout << endl;
	// for(int i=0; i<n; i++) {
	// 	cout << dp[i] << " ";
	// } cout << endl;
}