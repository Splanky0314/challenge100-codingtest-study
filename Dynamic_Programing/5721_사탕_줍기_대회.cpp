#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> map;
ll maxval;

vector<int> rowdp;

int calc_row(int i) {
    rowdp[0] = map[i][0];
    if(m == 1) return rowdp[0];
    rowdp[1] = max(rowdp[0], map[i][1]);

    for(int j=2; j<m; j++) {
        rowdp[j] = max(rowdp[j-1], rowdp[j-2] + map[i][j]);
    }

    int result = 0;
    for(int j=0; j<m; j++) {
        result = max(result, rowdp[j]);
    }
    return result;
}

int calc_best(vector<int> arr) {
    vector<int> dp(n);
    dp[0] = arr[0];
    dp[1] = max(dp[0], arr[1]);
    for(int j=2; j<n; j++) {
        dp[j] = max(dp[j-1], dp[j-2] + arr[j]);
    }

    int result = 0;
    for(int j=0; j<n; j++) {
        result = max(result, dp[j]);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true) {
        cin >> n >> m;
        if(n == 0 && m == 0) return 0;

        map.resize(n);
        rowdp.resize(m);
        for(int i=0; i<n; i++) {
            map[i].resize(m);
            for(int j=0; j<m; j++) {
                cin >> map[i][j];
            }
        }

        vector<int> rows(n);
        for(int i=0; i<n; i++) {
            rows[i] = calc_row(i);
            // cout << rows[i] << " ";
        }

        cout << calc_best(rows) << "\n";

        // cout << maxval << "\n";
    }
}