#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int n, m;
int map[100];
bool v[100];
pair<int,int> w[4];

void dfs(int x, int y) {
    v[x*m + y] = true;
    for(int k=0; k<4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if(0<=nx&&nx<n&&0<=ny&&ny<m&& !v[nx*m + ny] && map[nx*m + ny] == 0) {
            dfs(nx, ny);
        }
    }
}

int calc_safe_zone() {
    int sum = 0;
    for(int i=0; i<n*m; i++) {
        if(!v[i] && map[i] == 0) 
            sum++;
    }
    return sum;
}

void print() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << map[i*m + j] << "(" << v[i*m + j] << ") ";
        } cout << endl;
    } cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tmp;
    vector<pair<int,int>> vir;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> tmp;

            map[i*m + j] = tmp;
            if(tmp == 2) {
                vir.push_back({i, j});
            }
        }
    }

    // brute force select 3
    int ans = 0;
    for(int a=0; a<n*m; a++) {
        if(map[a] != 0) continue;
        map[a] = 9;

        for(int b=a+1; b<n*m; b++) {
            if(map[b] != 0) continue;
            map[b] = 9;

            for(int c=b+1; c<n*m; c++) {
                if(map[c] != 0) continue;
                map[c] = 9;

                fill_n(v, n*m, false);

                // start!!
                for(int i=0; i<vir.size(); i++) {
                    dfs(vir[i].first, vir[i].second);
                }

                int result = calc_safe_zone();
                ans = max(ans, result);
                // if(result == ans) {
                //     cout << result << endl;    
                //     print();
                // }
                map[c] = 0;
            }

            map[b] = 0;
        }

        map[a] = 0;
    }
    
    cout << ans;
}   