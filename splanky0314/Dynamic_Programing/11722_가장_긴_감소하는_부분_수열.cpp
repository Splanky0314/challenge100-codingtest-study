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

	int n;
	int arr[1001], dp[1001] = {};
	
	cin >> n;
	for(int i=0; i<n; i++) 
		cin >> arr[i];

	dp[0] = 1;
	bool found;
	for(int i=1; i<n; i++) {
		found = false;
		for(int j=0; j<i; j++) {
			if(arr[j] > arr[i] && dp[j] >= dp[i]) {
				found = true;
				dp[i] = dp[j] + 1;
			}
		}

		if(!found) {
			dp[i] = 1;
		}
	}

	int maxval = -1;
	for(int i=0; i<n; i++) {
		// cout << arr[i] << ": " << dp[i] << endl // for test
		if(maxval == -1 || maxval < dp[i]) {
			maxval = dp[i];
		}
	}

	cout << maxval;
}