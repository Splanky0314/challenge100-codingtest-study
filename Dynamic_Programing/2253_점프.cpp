#include <iostream>
#include <vector>
#include <algorithm>
#define INF 10000000

using namespace std;
using ll = long long;

int n, m;
bool issmall[10001];
int dp[10001][150]; // dp[i][j]: i번째 돌까지 필요한 최소의 점프 횟수 j == x
int minval = INF;

// x: 이전 점프한 칸 수, idx: 현재 idx
void jmp(int x, int idx, int cnt) {
    if(dp[idx][x] != 0 && dp[idx][x] <= cnt) return;
    else dp[idx][x] = cnt;
    
    if(idx == n) {
        minval = min(minval, cnt);
    }

    if(idx + (x+1) <= n && !issmall[idx + (x+1)])
        jmp(x+1, idx + (x+1), cnt+1);
    if(0 < x && idx + x <= n && !issmall[idx + x])
        jmp(x, idx + (x), cnt+1);
    if(0 < x-1 && idx + (x-1) <= n  && !issmall[idx + (x-1)]) 
        jmp(x-1, idx + (x-1), cnt+1);
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 2/24 17:00
    // x-1, x, x+1;

    int tmp;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> tmp; issmall[tmp] = true;
    }

    jmp(0, 1, 0);

    // // for test
    // for(int i=1; i<=n; i++) {
    //     cout << dp[i] << " ";
    // } cout << endl;

    if(minval == INF) cout << -1;
    else cout << minval;
}   