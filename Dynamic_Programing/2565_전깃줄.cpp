#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;

int n; 
vector<pair<int,int>> map;
int dp[501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int a, b;

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a >> b; map.push_back({a, b});
        dp[i] = 1; // init
    }

    // A 전봇대 기준으로 정렬
    sort(map.begin(), map.end());

    // B 기준으로 LIS
    int maxval = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) { // 작은 원소들만
            // 겹치지 않는 경우
            if(map[j].second < map[i].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxval = max(maxval, dp[i]);
    }

    cout << n - maxval;
}