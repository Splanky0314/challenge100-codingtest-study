#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n, k;
int a[21], b[21];
ll minval = -1;

void solve(int x, ll e, bool used) {
	if(x == n-1) {
		if(minval == -1 || minval > e) {
			minval = e;
			return;
		}
	}
	if(x+1<=n-1) solve(x+1, e+a[x], used);
	if(x+2<=n-1) solve(x+2, e+b[x], used);
	if(used == 0 && x+3 <= n-1) solve(x+3, e + k, 1);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i=0; i<n-1; i++) {
		cin >> a[i] >> b[i];
	}
	cin >> k;

	solve(0, 0, 0);
	cout << minval;
}