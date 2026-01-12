#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, tmp1, tmp2;
	vector<int> t;
	vector<int> p;
	vector<ll> dp;
	
	cin >> n;
	dp.resize(n+1, 0);
	t.push_back(0); p.push_back(0);
	for(int i=0; i<n; i++) {
		cin >> tmp1 >> tmp2;
		t.push_back(tmp1);
		p.push_back(tmp2);
	}

	for(int i=1; i<=n; i++) {
		if(1 <= i + t[i] -1 && i + t[i] - 1 <= n) { // 애초에 불가한 경우
			dp[i+t[i]-1] = max(dp[i+t[i]-1], dp[i-1] + p[i]);
		}
		// // for test
		// cout << "check" << i+t[i]-1 << endl;
		// cout << dp[i+t[i]-1] << "  " << dp[i-1] + p[i] << endl;
		
		if(dp[i-1] > dp[i]) {
			dp[i] = dp[i-1];
		}
	}

	// // for test
	// for(int i=0; i<=n; i++) {
	// 	cout << i << ": " << dp[i] << endl;
	// } cout << endl;

	ll maxval = -1;
	for(int i=1; i<=n; i++) {
		if(maxval == -1 || maxval < dp[i]) {
			maxval = dp[i];
		}
	}

	cout << maxval;
}