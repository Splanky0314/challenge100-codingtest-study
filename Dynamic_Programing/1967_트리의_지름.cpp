#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;
using ll = long long;

int n;
vector<pair<int,int>> g[10001];

int dp[10001];
int v[10001];
queue<pair<int, int>> q; // {node id, 현재까지 dist}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    cin >> n;
    for(int i=1; i<n; i++) {
        cin >> a >> b >> c; 
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    // 두 노드가 주어졌을 때, 그 사이 경로를 찾아야.
    // 두 노드는 무조건 leaf node일 것. bfs
    
    // 일단 leaf node(연결된 간선이 1개)를 찾아 bfs 시작
    int maxdist = 0;
    for(int i=1; i<=n; i++) {
        if(g[i].size() == 1) { // leaf node
            q.push({i, 0});
            v[i] = true;

            while(!q.empty()) {
                int node = q.front().first;
                int dist = q.front().second;
                q.pop();

                // cout << node << " " << dist << endl;

                for(pair<int,int> tmp: g[node]) {
                    if(!v[tmp.first] && dp[tmp.first] < dist + tmp.second) {
                        dp[tmp.first] = dist + tmp.second;
                        q.push({tmp.first, dist + tmp.second});
                        v[tmp.first] = true;

                        maxdist = max(maxdist, dist + tmp.second);
                    }    
                }
            }            

            // for tset
            // cout << "leaf " << i << endl;
            // for(int i=0; i<=n; i++) {
            //     cout << dp[i] << " ";
            // } cout << endl << endl;

            fill_n(dp, n+1, 0);
            fill_n(v, n+1, 0);
        }
    }

    // 그리고 거리 max값 찾기
    cout << maxdist;
}