#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int dp[2001]; // dp[i]: arr[i]보다 큰수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 
    int n;
    vector<int> arr;
    
    cin >> n; arr.resize(n+1);
    int maxval, totalmax = 0;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        maxval = 1;
        for(int j=0; j<i; j++) {
            if(arr[j] > arr[i]) {
                maxval = max(maxval, dp[j] + 1);
            }
        }
        dp[i] = maxval;
        totalmax = max(totalmax, maxval);
    }

    // for test
    // for(int i=0; i<n; i++) {
    //     cout << dp[i] << " ";
    // }

    cout << n - totalmax;
}   