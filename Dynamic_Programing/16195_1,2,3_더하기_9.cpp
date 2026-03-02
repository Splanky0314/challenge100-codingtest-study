#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000009;

using namespace std;
using ll = long long;

int n, m;
ll dp[1005][1001]; // dp[i][j] : j개의 수를 사용하여, i를 만들기 위한 방법의 수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 3/2 23:56
    // for test
    // cin >> n >> m;

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

    // // for test
    // for(int i=1; i<=100; i++) {
    //     for(int j=1; j<=10; j++) {
    //         cout << dp[i][j] << " ";
    //     } cout << endl;
    // }

    int T;
    cin >> T;
    for(int t=0; t<T; t++) {
        cin >> n >> m;

        ll sum = 0;
        for(int i=1; i<=m; i++) {
            sum = (sum + dp[n][i]) % MOD;
        }

        cout << sum << "\n";
    }
}