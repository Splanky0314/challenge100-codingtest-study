#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int dx[] = {0, 1};
int dy[] = {1, 0};

int n, m;
char map[101][101];
bool v[101][101];

void dfs(int x, int y, char tar) {
    v[x][y] = true;
    if(tar == '-') {
        int nx = x + dx[0];
        int ny = y + dy[0];
        if(nx < n && ny < m && !v[nx][ny] && map[nx][ny] == '-') {
            dfs(nx, ny, tar);
        }
    }
    else if(tar == '|') {
        int nx = x + dx[1];
        int ny = y + dy[1];
        if(nx < n && ny < m && !v[nx][ny] && map[nx][ny] == '|') {
            dfs(nx, ny, tar);
        }
    }
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
            if(!v[i][j]) {
                answer++;
                dfs(i, j, map[i][j]);
            }
        }  
    }
    cout << answer;
}