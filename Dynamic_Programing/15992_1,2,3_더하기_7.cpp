#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000009

using namespace std;
using ll = long long;

int n, m;
ll dp[1005][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 3/3 Tue 00:15

    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[3][1] = 1;

    for(int i=1; i<=1000; i++) {
        for(int j=1; j<=1000; j++) {
            if(dp[i][j] && j+1 <= 1000) {
                dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % MOD;
                dp[i+2][j+1] = (dp[i+2][j+1] + dp[i][j]) % MOD;
                dp[i+3][j+1] = (dp[i+3][j+1] + dp[i][j]) % MOD;
            }
        }
    }

    int T;
    cin >> T;
    for(int t=0; t<T; t++) {
        cin >> n >> m;
        cout << dp[n][m] << "\n";
    }
}