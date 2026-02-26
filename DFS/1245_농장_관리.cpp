#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, m;
int map[101][71];
bool v[101][71];

bool check(int x, int y) {
    v[x][y] = true;

    bool flag = true;

    for(int k=0; k<8; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if(0<=nx&&nx<n&&0<=ny&&ny<m && !v[nx][ny]) {
            if(map[x][y] > map[nx][ny]) { // x, y가 봉우리
                check(nx, ny);
            }
            else if(map[x][y] == map[nx][ny]) {
                if(check(nx, ny) == false) flag = false;
            }
            else { // nx, ny가 봉우리
                flag = false;
            }
        }
    }

    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 
    
    int tmp;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> tmp;
            if(tmp == 0) v[i][j] = true;     
            else map[i][j] = tmp;       
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!v[i][j]) {
                // cout << "search " << i << " " << j << endl;
                if(check(i,j)) {
                    // cout << i << " " << j << endl;
                    ans++;

                    // // for test
                    // for(int i=0; i<n; i++) {
                    //     for(int j=0; j<m; j++) {
                    //         cout << v[i][j] << " ";
                    //     } cout << endl;
                    // } cout << endl;
                }
            }
            
        }
    }

    cout << ans;
}   