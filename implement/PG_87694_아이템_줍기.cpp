#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ddx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int ddy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool map[104][104];
bool v[104][104];
int result = -1;

// dir: 0: up, 1: right, 2: down, 3: left
void dfs(int x, int y, int cnt, int finx, int finy) {
    if(x == finx && y == finy) {
        cout << "result! " << cnt << endl;
        if(result == -1 || result > cnt)
            result = cnt; 
        return;
    }
    
    v[x][y] = true;
    bool flag = true;
    
    for(int k=0; k<8; k++) {
        int nx = x+ddx[k], ny = y+ddy[k];
        if(map[nx][ny] == 0) {
            flag = false; break;
        }
    }
    if(flag) {
        v[x][y] = false; return;
    }
    cout << x << ", " << y << " " << cnt << endl;
    for(int k=0; k<4; k++) {
        int nx = x+dx[k], ny = y+dy[k];
        if(map[nx][ny] && !v[nx][ny]) {
            dfs(nx, ny, cnt+1, finx, finy);
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    int ans1, ans2;
    
    for(int i=0; i<rectangle.size(); i++) {
        int x1 = rectangle[i][0] * 2, y1 = rectangle[i][1] * 2;
        int x2 = rectangle[i][2] * 2, y2 = rectangle[i][3] * 2;
        for(int x=x1; x<=x2; x++) {
            for(int y=y1; y<=y2; y++) {
                map[x][y] = true;
            }
        }
    }
    
    // for test
    cout << endl;
    for(int i=0; i<12; i++) {
        for(int j=0; j<12; j++) {
            cout << map[i][j] << " ";
        } cout << endl;
    } cout << endl;
    
    int cnt = 0;
    int x = characterX * 2, y = characterY * 2;    
    dfs(x, y, 0, itemX*2, itemY*2);
    
    return result/2;
}