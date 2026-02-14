#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
vector<int> price(1001);
int dp[10001]; // dp[i]: 카드 i개를 샀을 때 최대 지불 금액

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 2/14 13:00
    
    cin >> n; 
    for(int i=1; i<=n; i++) {
        cin >> price[i];
    }

    for(int i=0; i<=n; i++) { // 현재 카드 개수
        for(int idx=1; i+idx<=n; idx++) { // 추가할 카드 개수
            if(dp[i + idx] < dp[i] + price[idx]) {
                dp[i + idx] = dp[i] + price[idx];
            }
        }
    }

    // // for test
    // for(int i=1; i<=n; i++) {
    //     cout << dp[i] << " ";
    // } 

    cout << dp[n];
}