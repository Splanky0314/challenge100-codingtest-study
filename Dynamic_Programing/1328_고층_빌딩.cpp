#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007

using namespace std;
using ll = long long;

ll dp[101][101];
ll facto[101]; // overflow 조심
ll comb[101][101];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, l, r;
	int left, right;
	ll sum = 0;
	cin >> n >> l >> r;

	// calc facto
	facto[0] = 1; facto[1] = 1;
	for(int i=2; i<=n; i++) {
		facto[i] = (facto[i-1] * i) % MOD;
	}

	// calc comb
	for(int i=0; i<=n; i++) {
		comb[i][0] = 1;
		comb[i][i] = 1;
	}
	for(int i=0; i<n; i++) {
		for(int j=1; j<i; j++) {
			comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
		}
	}

	// init dp
	for(int i=0; i<=n; i++) {
		dp[i][i] = 1;
	}
	// i: 제일 큰 빌딩의 위치
	for(int N=2; N<=n; N++) {
		for(int i=1; i<N; i++) { // i : 보이는 빌딩 수
			sum = 0;
			// j : 제일 큰 빌딩의 위치
			// for(int j=i; j<=N; j++) {
			for(int j=1; j<=N; j++) {
				left = j-1;
				right = N-j;
				sum = (sum + ((dp[left][i-1] * facto[right]) % MOD * comb[N-1][right]) % MOD) % MOD;
			}
			dp[N][i] = sum;
		}
	}

	// for test
	// for(int i=1; i<=n; i++) {
	// 	for(int j=1; j<=n; j++) {
	// 		cout << dp[i][j] << " ";
	// 	} cout << endl;
	// } cout << endl;

	
	sum = 0;
	// j : 제일 큰 빌딩의 위치
	for(int j=l; j<=n-r+1; j++) {
		left = j-1;
		right = n-j;
		sum = (sum + (dp[left][l-1] * dp[right][r-1]) % MOD * comb[n-1][left] % MOD) % MOD;
	}
	
	cout << sum;
}