#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

typedef struct Elem {
    int x, y, dist;
} Elem;

int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};

int n,m;
bool map[1001][1001];
int ans[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 
    int tmp;
    queue<Elem> q;
    Elem start;

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> tmp;
            if(tmp == 2) {
                start = {i, j, 0};
                map[i][j] = 1;
                ans[i][j] = 1;
                q.push({i, j, 1});
            }
            else {
                map[i][j] = tmp;
            }
        }
    }

    int x, y, dist;
    while(!q.empty()) {
        x = q.front().x;
        y = q.front().y;
        dist = q.front().dist;
        q.pop();

        for(int k=0; k<4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if(0<=nx&&nx<n&&0<=ny&&ny<m && !ans[nx][ny] && map[nx][ny]) {
                ans[nx][ny] = dist + 1;
                q.push({nx, ny, dist + 1});
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j] == 1 && ans[i][j] == 0) {
                cout << -1 << " ";
            }
            else if(map[i][j] == 0) cout << 0 << " ";
            else cout << ans[i][j]-1 << " ";
        } cout << "\n";
    }
}   