#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
int squ[500];
// dp[i]: i를 만들 때 필요한 항의 최소 개수
int dp[100001]; 

// i--하면서 모든 경우의 수 고려하기
void solve(int sum, int i, int cnt) {
    // cout << sum << ", " << i << " " << cnt << endl;
    if(sum >= n) return;
    if(i <= 0) return;

    if(sum + squ[i] <= n) {
        // dp[sum + squ[i]] = min(dp[sum + squ[i]], cnt + 1);
        if(dp[sum + squ[i]] > cnt + 1) {
            dp[sum + squ[i]] = cnt + 1;
            solve(sum + squ[i], i, cnt+1); // i 다시한번 사용 기회
            solve(sum + squ[i], i-1, cnt+1); // i 사용하고, 다음 후보로
        }
        
    }
    solve(sum, i-1, cnt); // i 사용 안하고, 다음 후보로
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // 중복 사용도 가능함!!
    cin >> n;

    int i = 1;
    while(i*i <= n) {
        squ[i] = i*i;
        i++;
    }
    for(int j=0; j<=n; j++) dp[j] = 1000000;

    solve(0, i-1, 0);

    // // for test
    // for(int j=0; j<=n; j++) {
    //     cout << dp[j] << " ";
    // } cout << endl;

    cout << dp[n];
}