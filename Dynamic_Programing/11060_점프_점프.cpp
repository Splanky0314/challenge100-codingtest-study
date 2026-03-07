#include <iostream>
#include <vector>
#include <algorithm>
#define INF 100000000

using namespace std;
using ll = long long;

int n;
int map[1001];
int dp[1001]; // i에 도달하기 까지 필요한 최소 점프 횟수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 3/7 Sat 11:32
    // 못가면 -1
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> map[i];
        dp[i] = INF;
    }

    dp[0] = 0;
    for(int i=0; i<n; i++) {
        if(dp[i] == INF) continue;
        for(int j=1; j<=map[i]; j++) {
            if(i+j <= n-1)
                dp[i+j] = min(dp[i+j], dp[i] + 1);
        }
    }

    // // for test
    // for(int i=0; i<n; i++) {
    //     cout << dp[i] << " ";
    // }

    if(dp[n-1] == INF) cout << -1;
    else cout << dp[n-1];
}