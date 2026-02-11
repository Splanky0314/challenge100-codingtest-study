#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

typedef struct Pos {
    int x, y, z;
} Pos;

int dx[] = {-1, 0, 0, 0, 0, 1};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, -1, 0, 0, 1, 0};

int m, n, h;
int map[101][101][101]; // map[z][x][y]

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 2/11 16:20
    queue<Pos> q;
    int tmp;

    cin >> m >> n >> h;
    for(int k=0; k<h; k++) 
        for(int i=0; i<n; i++) 
            for(int j=0; j<m; j++) {
                cin >> tmp; map[k][i][j] = tmp;
                if(tmp == 1) q.push({i,j,k});
            }    
    
    while(!q.empty()) {
        Pos pos = q.front(); q.pop();
        int target = map[pos.z][pos.x][pos.y];

        for(int l=0; l<6; l++) {
            int x = pos.x + dx[l];
            int y = pos.y + dy[l];
            int z = pos.z + dz[l];

            if(0<=x&&x<n&&0<=y&&y<m&&0<=z&&z<h) {
                int color = map[z][x][y];
                if(color == 0 || color > target+1) {
                    map[z][x][y] = target+1;
                    q.push({x, y, z});
                }
            }
        }

        // // for test
        // for(int k=0; k<h; k++) {
        //     for(int i=0; i<n; i++) {
        //         for(int j=0; j<m; j++) {
        //             cout << map[k][i][j] << " ";
        //         } cout << endl;
        //     } cout << endl; 
        // } cout << "-----------------" << endl;
            
    }

    int maxval = -1;
    for(int k=0; k<h; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int tmp = map[k][i][j];
                if(tmp == 0) {
                    cout << -1; return 0;
                } 
                if(tmp == -1) continue;
                else if(maxval == -1 || maxval < tmp) {
                    maxval = tmp-1;
                }
            }
        }
    }

    cout << maxval;
}