#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define INF 10000000

using namespace std;
using ll = long long;

typedef struct Elem {
    int x, y, dist;
} Elem;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, m;
int map[51][51];
bool v[51][51];

int bfs(int x, int y) {
    queue<Elem> q; int dist;
    v[x][y] = true;
    q.push({x, y, 0});

    while(!q.empty()) {
        x = q.front().x;
        y = q.front().y;
        dist = q.front().dist;
        q.pop();
        
        for(int k=0; k<8; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(0<=nx&&nx<n&&0<=ny&&ny<m &&!v[nx][ny]) {
                if(map[nx][ny] == 1) {
                    return dist + 1;
                }
                else {
                    v[nx][ny] = true;
                    q.push({nx, ny, dist + 1});
                }
            }
        }
    }

    return INF;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }

    int answer = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j] == 0) {
                fill_n(&v[0][0], n*51, false);
                int result = bfs(i, j);
                answer = max(answer, result);
            }
        }
    }
  
    cout << answer;
}