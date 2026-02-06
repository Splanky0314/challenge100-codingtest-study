#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int solve(int n, int m, ll ans) {
	// cout << n << " " << m << endl; // for test
	if(n == m) {
		return ans;
	}
	
	n %= m;
	if(n==0) {
		return ans;
	}

	int leftover = m%n;
	if(leftover == 0) {
		ans += (m/n - 1)*n;
	}
	else {
		ans += (m/n)*n;

		// 나머지 처리
		if(n%leftover != 0) {
			return solve(n, m-((m/n)*n), ans);
		}
	}
	return ans;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	cout << solve(n, m, 0);
}