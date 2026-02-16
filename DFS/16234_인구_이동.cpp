#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int n, l, r;
int map[51][51];
int v[51][51]; // 0: 미방문 1:방문 완 2: 후보지

// return {total_polulation, cnt}
pair<int,int> find_countries(int x, int y) {
    pair<int,int> res = {map[x][y], 1};
    v[x][y] = 2;

    for(int k=0; k<4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if(0<=nx&&nx<n&&0<=ny&&ny<n && v[nx][ny] == 0) {
            int diff = abs(map[x][y] - map[nx][ny]);
            if(l<=diff && diff<=r) {
                pair<int,int> tmp = find_countries(nx, ny);
                res.first += tmp.first;
                res.second += tmp.second;
            }
        }
    }

    return res;
}

// v[x][y] == 2 인 곳을
void fill_map(int x, int y, int val) {
    map[x][y] = val;
    v[x][y] = 1;

    for(int k=0; k<4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if(0<=nx&&nx<n&&0<=ny&&ny<n && v[nx][ny] == 2) {
            fill_map(nx, ny, val);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l >> r;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> map[i][j];
        }
    }

    bool is_changed;
    for(int t=0; ; t++) {
        is_changed = false;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(v[i][j] == 0) {
                    pair<int,int> res = find_countries(i, j);
                    if(res.second == 1) {
                        v[i][j] = 1;
                    }
                    else {
                        is_changed = true;
                        fill_map(i, j, res.first / res.second);
                    }
                }
                
            }
        }

        if(!is_changed) {
            cout << t; return 0;
        }

        // // for test
        // cout << t << endl;
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<n; j++) {
        //         cout << map[i][j] << " ";
        //     } cout << endl;
        // } cout << endl;

        fill_n(&v[0][0], 51*n, 0);
    }
}   