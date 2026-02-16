#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;
using ll = long long;

typedef struct Elem {
    int x, y, dist;
} Elem;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int l, w; 
bool map[51][51];
bool v[51][51];

int bfs(int x, int y) {
    queue<Elem> q;
    v[x][y] = true;
    q.push({x, y, 0});

    int dist;
    while(!q.empty()) {
        x = q.front().x; y = q.front().y; 
        dist = q.front().dist; q.pop();
        for(int k=0; k<4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if(0<=nx&&nx<l&&0<=ny&&ny<w && !v[nx][ny] && map[nx][ny]) {
                v[nx][ny] = true;
                q.push({nx, ny, dist + 1});
            }
        }
    }
    
    return dist; // check!
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char c;

    cin >> l >> w;
    for(int i=0; i<l; i++) {
        for(int j=0; j<w; j++) {
            cin >> c;
            if(c == 'W') map[i][j] = 0; // sea
            else map[i][j] = 1; // 육지
        }
    }

    // // for test
    // for(int i=0; i<l; i++) {
    //     for(int j=0; j<w; j++) {
    //         cout << map[i][j] << " ";
    //     } cout << endl;
    // } cout << endl;

    int maxval = 0;
    for(int i=0; i<l; i++) {
        for(int j=0; j<w; j++) {
            if(!v[i][j] && map[i][j]) {
                int res = bfs(i, j);
                maxval = max(res, maxval);
                fill_n(&v[0][0], 51*51, 0);
            }
        }
    }

    cout << maxval;
}   