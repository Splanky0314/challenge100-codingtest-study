#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define INF 100000000

using namespace std;
using ll = long long;

int n, m, x;
vector<pair<int,int>> g[1001];
int dist[1001];
int dist2[1001];
bool v[1001];

int return_minidx() {
    int minval = INF, minidx;
    for(int i=1; i<=n; i++) {
        if(!v[i] && minval > dist[i]) {
            minval = dist[i]; minidx = i;
        }
    }
    if(minval == INF) return -1;
    return minidx;
}

int return_minidx2() {
    int minval = INF, minidx;
    for(int i=1; i<=n; i++) {
        if(!v[i] && minval > dist2[i]) {
            minval = dist2[i]; minidx = i;
        }
    }
    if(minval == INF) return -1;
    return minidx;
}


void dij(int a) {
    dist[a] = 0;
    while(true) {
        v[a] = true;
        for(pair<int,int> y: g[a]) {
            int b = y.first;
            int w = y.second;
            if(!v[b]) {
                dist[b] = min(dist[b], dist[a] + w);
            }
        }

        a = return_minidx();
        if(a == -1) break;
    }

    // int maxval = -1;
    // for(int i=1; i<=n; i++) {
    //     maxval = max(maxval, dist[i]);
    // }
    // return maxval;
}

int dij(int a, int dest) {
    fill_n(dist2, (n+1), INF);
    fill_n(v, (n+1), false);

    dist2[a] = 0;
    if(a == dest) return dist2[a];
    while(true) {
        v[a] = true;
        for(pair<int,int> y: g[a]) {
            int b = y.first;
            int w = y.second;
            if(!v[b]) {
                dist2[b] = min(dist2[b], dist2[a] + w);
            }
        }

        a = return_minidx2();
        if(a == -1) break;
        if(a == dest) {
            return dist2[a];
        }
    }
    return dist2[dest];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 2/28 Sat 15:24
    int a, b, c; 
    
    cin >> n >> m >> x;
    fill_n(dist, (n+1), INF);

    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }

    dij(x);
    int maxval = -1;
    for(int i=1; i<=n; i++) {
        // cout << dij(i, x) << endl;
        maxval = max(maxval, dist[i] + dij(i, x));
    }

    cout << maxval;

    // for test
    // cout << endl;
    // for(int i=1; i<=n; i++) {
    //     cout << dist[i] << " ";
    // } cout << endl;
}   