#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
int arr[1001];
int dp[1001]; // dp[i]: 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        
        int maxval = 1;
        for(int j=0; j<i; j++) {
            if(arr[j] < arr[i]) {
                maxval = max(maxval, dp[j] + 1);
            }
        }
        dp[i] = maxval;
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, dp[i]);
        // cout << dp[i] << " "; // for test
    } 
    
    cout << ans;     
}   