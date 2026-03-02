#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define INF 1000000

using namespace std;
using ll = long long;

typedef struct Elem {
    int a, b, w;

    bool operator<(const Elem &e) const {
        return w < e.w;
    }
} Elem;

int n, m, k;
vector<Elem> g;
int parent[1001];

int find(int a) {
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

bool unionfunc(int a, int b) {
    a = find(a); b = find(b);
    if(a == b) return false;
    parent[b] = a; return true;
}

void initparent() {
    for(int i=1; i<=n; i++)
        parent[i] = i;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 3/2 22:54
    int a, b;

    cin >> n >> m >> k;
    for(int i=1; i<=m; i++) {
        cin >> a >> b;
        // if(b > a) swap(a, b);
        g.push_back({a, b, i});
    }

    int x, y, w;
    for(int t=0; t<k; t++) {
        initparent();

        int sum = 0;
        int cnt = 0;
        int delidx;
        for(int i=0; i<m; i++) {
            x = g[i].a; y = g[i].b; w = g[i].w;
            if(w == INF) continue;
            if(unionfunc(x, y)) {
                if(cnt == 0) delidx = i;
                cnt++;
                sum += w;
                // cout << x << " " << y << " " << w << endl; // for test
            }
            if(cnt == n-1) break;
        }
        if(cnt < n-1) {
            for(int j=t; j<k; j++) {
                cout << "0 ";
            }
            return 0;
        }
        
        cout << sum << " ";
        g[delidx].w = INF;
    }
}