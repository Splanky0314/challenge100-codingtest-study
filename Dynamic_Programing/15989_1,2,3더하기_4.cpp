#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
int dp[10005][4]; // dp[i][1,2,3]: i 만들기까지 마지막 수로 j사용

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 2/18 15:10
    int T;
    cin >> T;
    for(int t=0; t<T; t++) {
        cin >> n;
        fill_n(&dp[0][0], (n+1)*4, 0);
        dp[1][1] = 1; dp[2][2] = 1; dp[3][3] = 1;

        for(int i=0; i<n; i++) {
            // 1 사용
            dp[i+1][1] += dp[i][1];

            // 2 사용
            dp[i+2][2] += dp[i][1] + dp[i][2];

            // 3 사용
            dp[i+3][3] += dp[i][1] + dp[i][2] +dp[i][3];
        }

        // // for test
        // for(int i=1; i<=n; i++) {
        //     for(int j=1; j<=3; j++) {
        //         cout << dp[i][j] << " ";
        //     } cout << endl;
        // } cout << endl;

        cout << (dp[n][1] + dp[n][2] + dp[n][3]) << "\n";
    }

}   