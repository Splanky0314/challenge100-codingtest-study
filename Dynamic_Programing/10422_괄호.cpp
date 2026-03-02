#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007

using namespace std;
using ll = long long;

int l;
ll dp[5001];
ll uniq[5001];

ll solve(int x) {
    // if(x == 0) return 0;
    if(dp[x]) return dp[x];

    ll result = solve(x-2);
    for(int i=2; i<x; i+=2) {
        result = (result + ((solve(i) * uniq[x - i]) % MOD)) % MOD;
    }
    uniq[x] = dp[x-2];
    return dp[x] = result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    dp[2] = 1;
    uniq[2] = 1;
    dp[4] = 2;
    uniq[4] = 1;

    cin >> T;
    for(int t=0; t<T; t++) {
        cin >> l;
        if(l%2) {
            cout << "0\n"; continue;
        }

        cout << solve(l) << "\n";
    }

    // for test
    // for(int i=0; i<500; i++) {
    //     for(int j=0; j<10; j++) {
    //         cout << dp[i*10 + j] << " ";
    //     }
    //     cout << endl;
    // }

    
    // cout << "UNIQUE" << endl;
    // for(int i=0; i<500; i++) {
    //     for(int j=0; j<10; j++) {
    //         cout << uniq[i*10 + j] << " ";
    //     } cout << endl;
    // }
}   