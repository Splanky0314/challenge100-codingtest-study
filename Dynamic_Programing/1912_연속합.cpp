#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
int arr[100001] = {};
int dp[100001] = {};

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i=0; i<n; i++) 
		cin >> arr[i];

	dp[0] = arr[0];
	for(int i=1; i<n; i++) {
		if(dp[i-1] > 0) dp[i] = dp[i-1] + arr[i];
		else dp[i] = arr[i];
	}

	int maxval = dp[0];
	for(int i=1; i<n; i++) {
		if(maxval < dp[i]) {
			maxval = dp[i];
		}
	}
	cout << maxval;
}