#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n, k;
vector<int> coin;
int dp[10001]; // dp[sum]: sum이 되는 경우의 수 
int cnt = 0;

// 오답 - 이 함수 사용하면 시간초과 발생
void solve(int idx, int sum) {
    // cout << idx << " " << sum << endl;
    if(idx >= n) return;
    if(sum > k) return;
    if(sum == k) {
        cnt++; return;
    }

    // 쓰고 재사용 가능
    solve(idx, sum+coin[idx]); // 쓰고 다음거
    solve(idx+1, sum); // 안쓰고 다음거
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // s#1000.. *g3..s3 !@$me
    
    int tmp;
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        cin >> tmp; coin.push_back(tmp);
    }

    sort(coin.begin(), coin.end());

    for(int i=0; i<n; i++) {
        int tar = coin[i];
        for(int l=k; l>=1; l--) {
            for(int j=tar; l-j>=1; j+=tar) {
                dp[l] += dp[l-j];
            }
        }

        for(int j=tar; j<=k; j+=tar) dp[j]++;

        // for test
        // cout << "<< " << coin[i] << endl;
        // for(int i=1; i<=k; i++) {
        //     cout << dp[i] << " ";
        // } cout << endl;
    }

    cout << dp[k];
}