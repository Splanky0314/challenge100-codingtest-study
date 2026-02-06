#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000000

using namespace std;
using ll = long long;

int dp[1000001];

int solve(int x) {
	if(x == 1) return 0;
	if(dp[x]) return dp[x];

	// cout << "called: " << x << endl;

	int r1 = MAX, r2 = MAX, r3 = MAX;
	if(x%3 == 0) r1 = solve(x/3) + 1;
	if(x%2 == 0) r2 = solve(x/2) + 1;
	if(x>1) r3 = solve(x-1) + 1;

	return dp[x] = min(r1, min(r2, r3));
}

void track(int x) {
	cout << x << " ";
	if(x == 1) return;

	int r1 = MAX, r2 = MAX, r3 = MAX;
	if(x%3 == 0) r1 = dp[x/3];
	if(x%2 == 0) r2 = dp[x/2];
	if(x>1) r3 = dp[x-1];

	int minval = min(r1, min(r2, r3));
	if(minval == MAX) return;
	else if(minval == r1) track(x/3);
	else if(minval == r2) track(x/2);
	else if(minval == r3) track(x-1);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	solve(n);

	// for(int i=1; i<=n; i++) {
	// 	cout << dp[i] << " ";
	// } cout << endl;

	cout << dp[n] << "\n";
	track(n);
}