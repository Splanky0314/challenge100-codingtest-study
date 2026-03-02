#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n, m;
int map[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true) {
        cin >> n >> m;
        if(n == 0 && m == 0) return 0;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                cin >> map[i][j];

                if(map[i][j] == 1) {
                    map[i][j] = min(map[i-1][j], min(map[i-1][j-1], map[i][j-1])) + 1;
                }
            }
        }

        // start
        int maxval = 0;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                maxval = max(maxval, map[i][j]);
            }
        }

        cout << maxval << "\n";
    }
}   