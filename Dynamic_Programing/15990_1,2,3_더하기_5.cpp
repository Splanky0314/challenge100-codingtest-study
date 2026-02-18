#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000009

using namespace std;
using ll = long long;

int n;
int dp[100005][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 2/18 14:40 ~ 14:54
    int T;
    
    cin >> T;
    for(int t=0; t<T; t++) {
        cin >> n;

        fill_n(&dp[0][0], (n+1)*4, 0);
        dp[1][1] = 1; dp[2][2] = 1; dp[3][3] = 1;

        for(int i=0; i<n; i++) {
            // 1 사용
            dp[i+1][1] = (dp[i+1][1] + (dp[i][2] + dp[i][3]) % MOD) % MOD;

            // 2 사용
            dp[i+2][2] = (dp[i+2][2] + (dp[i][1] + dp[i][3]) % MOD) % MOD;

            // 3 사용
            dp[i+3][3] = (dp[i+3][3] + (dp[i][1] + dp[i][2]) % MOD) % MOD;
        }

        // // for test
        // for(int i=1; i<=n; i++) {
        //     for(int j=1; j<=3; j++) {
        //         cout << dp[i][j] << " ";
        //     } cout << endl;
        // } cout << endl;

        int ans = (dp[n][1] + dp[n][2]) % MOD;
        ans = (ans +dp[n][3]) % MOD;
        cout << ans << "\n";
    }
}   