#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 100000000

using namespace std;
using ll = long long;

int n;
int map[10010];
int dp[10010];
bool v[10010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    queue<int> q;

    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> map[i];
        dp[i] = INF; // initialize
    } 
    cin >> a >> b;
    q.push(a); dp[a] = 0;
    
    // TODO: v 체크 해야되나??
    int i = 0;
    while(!q.empty()) {
        i = q.front(); 
        v[i] = true;
        q.pop();
        // if(dp[i] == INF) continue; 

        // 오른쪽으로 jump!
        for(int dist = map[i]; i + dist <= n; dist += map[i]) {
            if(dp[i + dist] > dp[i] + 1) {
                dp[i + dist] = dp[i] + 1;
                q.push(i + dist);
            }
        }

        // 왼쪽으로 jump!
        for(int dist = map[i]; i - dist >= 1; dist += map[i]) {
            if(dp[i - dist] > dp[i] + 1) {
                dp[i - dist] = dp[i] + 1;
                q.push(i - dist);
            }
        }
    }

    // // for test
    // for(int i=1; i<=n; i++) {
    //     cout << dp[i] << " ";
    // } cout << endl << endl;

    if(dp[b] == INF) cout << -1;
    else cout << dp[b];
}