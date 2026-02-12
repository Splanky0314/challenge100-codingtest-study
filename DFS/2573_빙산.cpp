#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int n, m;
int map[301][301];
int map2[301][301];
int visit[301][301];

void dfs(int x, int y, int color, int result[][301]) {
    // cout << x << "," << y << endl;
    visit[x][y] = color;

    for(int k=0; k<4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if(0<=nx&&nx<n&&0<=ny&&ny<m && result[nx][ny] != 0 && visit[nx][ny] != color) {
            dfs(nx, ny, color, result);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 2/13 01:00
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }

    // 1. 녹이기 -> 2. 분리되었나 측정
    // 다 녹을 때까지 분리되지 않는 경우 처리
    int (*cur)[301] = map;
    int (*result)[301] = map2;
    bool ischanged;
    for(ll year = 1; ; year++) {
        ischanged = false;
        
        // 1. 녹이기 - 처음엔 무조건 한 덩어리의 빙산 주어짐
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int hei = cur[i][j];
                if(hei != 0) {
                    for(int k=0; k<4; k++) {
                        int nx = i + dx[k], ny = j + dy[k];
                        if(0<=nx&&nx<n&&0<=ny&&ny<m && cur[nx][ny] == 0) {
                            hei--;
                        }
                    }
                    result[i][j] = max(0, hei);
                    if(hei != cur[i][j]) ischanged = true;
                }
            }
        }

        // // for test
        // cout << "<< " << year << endl;
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<m; j++) {
        //         cout << result[i][j] << " ";
        //     } cout << endl;
        // } cout << endl;

        if(!ischanged) { // 분리되지 않는 경우
            cout << 0; return 0;
        }

        // 2. 분리되었나 측정
        bool fir = true;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(fir && result[i][j] != 0) {
                    dfs(i, j, year, result); fir = false;
                }
                // 분리된 경우!
                else if(result[i][j] != 0 && visit[i][j] != year) {
                    cout << year; return 0;
                }
            }
        }

        // // for test
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<m; j++) {
        //         cout << visit[i][j] << " ";
        //     } cout << endl;
        // }
                
    
        swap(cur, result);
        fill_n(&result[0][0], 301*301, 0);
    }
}