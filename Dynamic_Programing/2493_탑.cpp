#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int dp[500001]; // dp[i] : arr[i]보다 높은 건물의 idx

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, tmp;
    vector<int> arr;

    cin >> n; arr.resize(n+1);
    for(int i=1; i<=n; i++) {
        cin >> tmp; arr[i] = tmp;
        
        int j = i-1;
        while(j>=1) {
            if(arr[j] > arr[i]) {
                dp[i] = j;
                break;
            }
            else {
                j = dp[j];
            }
        }
    }

    for(int i=1; i<=n; i++) {
        cout << dp[i] << " ";
    }

    
}   