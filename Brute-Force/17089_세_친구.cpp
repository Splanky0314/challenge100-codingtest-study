#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n, m;
bool g[4001][4001];
int cntfri[4001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 3/3 Tue 00:21
    int a, b;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        g[a][b] = true; g[b][a] = true;
        cntfri[a]++;
        cntfri[b]++;
    }

    int minval = 1000000000;
    for(int i=1; i<=n; i++) {
        if(cntfri[i] < 2) continue;

        for(int j=i+1; j<=n; j++) {
            if(cntfri[j] < 2 || g[i][j] == 0) continue;

            for(int k=j+1; k<=n; k++) {
                if(cntfri[k] < 2) continue;
                if(g[i][j] && g[j][k] && g[k][i]) {
                    int result = cntfri[i] + cntfri[j] + cntfri[k] - 6;
                    minval = min(minval, result);
                }
            }
        }
    }

    if(minval == 1000000000) cout << -1;
    else cout << minval;
}