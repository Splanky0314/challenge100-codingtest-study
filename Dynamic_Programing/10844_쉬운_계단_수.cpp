#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000000

using namespace std;
using ll = long long;

ll dp[101][10];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	ll sum = 0;

	cin >> n;

	for(int i=1; i<10; i++) dp[1][i] = 1;

	for(int i=2; i<=n; i++) {
		for(int j=0; j<10; j++) { // 각 숫자별로
			if(j-1 >= 0) dp[i][j-1] = (dp[i][j-1] + dp[i-1][j]) % MOD;
			if(j+1 <= 9) dp[i][j+1] = (dp[i][j+1] + dp[i-1][j]) % MOD;
		}
	}

	for(int i=0; i<10; i++) {
		sum = (sum + dp[n][i]) % MOD;
	}

	cout << sum;
}