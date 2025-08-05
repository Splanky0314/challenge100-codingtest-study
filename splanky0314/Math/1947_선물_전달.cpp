#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000000

using namespace std;
using ll = long long;

int n;
ll dp[1000001];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;	

	// 확률식을 수열, 점화식 형태로 사고하기
	dp[2] = 1;
	dp[3] = 2;
	for(int i=4; i<=n; i++) {
		dp[i] = ((dp[i-1] + dp[i-2]) % MOD * (i-1)) % MOD;
	}

	cout << dp[n];
} 