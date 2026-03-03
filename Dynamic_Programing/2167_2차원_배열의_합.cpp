#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
using ll = long long;

int n, m;
int map[301][301];
int dp[301][301]; // dp[i][j]: (1,1) ~ (i,j)까지의 합

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 3/3 Tue 16:22
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> map[i][j];
            dp[i][j] = map[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }

    int t, a, b, c, d;
    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> a >> b >> c >> d;
        cout << (dp[c][d] - dp[a-1][d] - dp[c][b-1] + dp[a-1][b-1]) << "\n";
    } 

    // // for test
    // cout << endl;
    // for(int i=1; i<=n; i++) {
    //     for(int j=1; j<=m; j++) {
    //         cout << dp[i][j] << " ";
    //     } cout << endl;
    // } cout << endl;
}