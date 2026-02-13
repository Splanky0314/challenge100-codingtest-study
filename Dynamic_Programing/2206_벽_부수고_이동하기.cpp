#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define INF 10000000

using namespace std;
using ll = long long;

typedef struct Elem {
    int x, y;
    bool used;
} Elem;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int n, m;
string map[1001];
int dp[1001][1001]; // dp[i][j]: 벽 안부수고 (i, j) 도달하기까지 최단거리
int useddp[1001][1001]; // dp[i][j]: 벽 1회 부수로 (i,j )도달하기 까지 최단거리

queue<Elem> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 2/13 13:50
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> map[i];
    fill_n(&dp[0][0], 1001*1001, INF);
    fill_n(&useddp[0][0], 1001*1001, INF);

    dp[0][0] = 1;

    q.push({0, 0, false});
    while(!q.empty()) {
        Elem tmp = q.front(); q.pop();
        int x = tmp.x, y = tmp.y;
        bool used = tmp.used;
        int dist;

        if(used == true) dist = useddp[x][y];
        else dist = dp[x][y];

        // cout << x << "," << y << " - " << dist << endl; // for test

        for(int k=0; k<4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if(0<=nx&&nx<n&&0<=ny&&ny<m) {
                if(map[nx][ny] == '1' && used == false) { // Wall
                    if(useddp[nx][ny] > dist + 1 && dp[nx][ny] > dist + 1) {
                        useddp[nx][ny] = dist + 1;
                        q.push({nx, ny, true});
                    }
                    
                }
                else if(map[nx][ny] == '0') {
                    if(used == true) {
                        if(useddp[nx][ny] > dist + 1 && dp[nx][ny] > dist + 1) {
                            useddp[nx][ny] = dist + 1;
                            q.push({nx, ny, true});
                        }
                    }
                    else {
                        if(dp[nx][ny] > dist + 1) {
                            dp[nx][ny] = dist + 1;
                            q.push({nx, ny, false});
                        }
                    }
                }
            }
        }
    }

    // // for test
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         if(dp[i][j] >= 1000000) cout << "X ";
    //         else cout << dp[i][j] << " ";
    //     } cout << endl;
    // } cout << endl;

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         if(useddp[i][j] >= 1000000) cout << "X ";
    //         else cout << useddp[i][j] << " ";
    //     } cout << endl;
    // } cout << endl;
    
    // output

    int result1 = dp[n-1][m-1];
    int result2 = useddp[n-1][m-1];
    if(result1 != INF && result2 != INF) {
        cout << min(result1, result2);
    }
    else if(result1 != INF) cout << result1;
    else if(result2 != INF) cout << result2;
    else cout << -1; 
}