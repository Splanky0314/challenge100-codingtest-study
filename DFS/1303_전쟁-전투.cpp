#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int n, m;
bool v[101][101];
string map[101];

int dfs(int x, int y, char tar) {
    int sum = 1;
    v[x][y] = true;
    for(int k=0; k<4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(0<=nx&&nx<n&&0<=ny&&ny<m&& !v[nx][ny] && map[nx][ny] == tar) {
            sum += dfs(nx, ny, tar);
        }
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n; 
    for(int i=0; i<n; i++) {
        cin >> map[i];
    }

    int w = 0;
    int b = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!v[i][j]) {
                if(map[i][j] == 'W') {
                    int tmp = dfs(i, j, 'W');
                    w += tmp*tmp;
                }
                else if(map[i][j] == 'B') {
                    int tmp = dfs(i, j, 'B');
                    b += tmp*tmp;
                }
            }
        }
    }

    cout << w << " " << b;
}