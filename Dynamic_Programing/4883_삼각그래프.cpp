#include <iostream>
#include <vector>
#include <algorithm>
#define INF 10000000

using namespace std;
using ll = long long;

int n;
int map[100001][3];
int dp[100001][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //
    int tmp;
    int t = 1;
    while(true) {
        fill_n(&dp[0][0], (n+1)*3, 0);

        cin >> n;
        if(n == 0) return 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<3; j++) {
                cin >> tmp;
                map[i][j] = tmp;
            }
        }

        dp[0][0] = INF;
        dp[0][1] = map[0][1]; 
        dp[0][2] = map[0][2] + dp[0][1];
        dp[1][0] = map[1][0] + dp[0][1];

        for(int i=1; i<n; i++) {
            if(i==1) dp[i][0] = map[i][0] + dp[0][1];

            // 0
            dp[i][0] = map[i][0] + min(dp[i-1][0], dp[i-1][1]);

            // 1
            dp[i][1] = map[i][1] + min(min(dp[i][0], dp[i-1][0]), min(dp[i-1][1], dp[i-1][2]));

            // 2
            dp[i][2] = map[i][2] + min(min(dp[i-1][1], dp[i-1][2]), dp[i][1]);
        }

        // for test
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<3; j++) {
        //         cout << dp[i][j] << " ";
        //     }cout << endl;
        // }cout  << endl;

        cout << t << ". ";
        cout << dp[n-1][1] << "\n";

        t++;
    }

    
}   