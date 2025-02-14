#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int V, E, K;
vector<int> mdis;
vector<bool> visited;
vector<vector<pair<int, int>>> g;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; 

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> V >> E >> K;
    mdis.resize(V+1);
    fill(mdis.begin(), mdis.end(), INT_MAX);
    visited.resize(V+1);
    fill(visited.begin(), visited.end(), false);
    g.resize(V+1);

    int u, v, w;
    for(int i=0; i<E; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    q.push({0, K}); // {mdis[K], K} mdis[] 작은거 순으로 빼내기 위함
    mdis[K] = 0;
    while(!q.empty()) {
        pair<int, int> cur = q.top();
        q.pop();
        int cur_v = cur.second;
        if(visited[cur_v]) continue;
        visited[cur_v] = true;

        for(pair<int, int> tmp: g[cur_v]) {
            int nxt = tmp.first;
            int wei = tmp.second;

            if(mdis[nxt] > mdis[cur_v] + wei) {
                mdis[nxt] = mdis[cur_v] + wei;
                q.push({mdis[nxt], nxt});
            }
        }
    }

    for(int i=1; i<=V; i++) {
        if(visited[i]) cout << mdis[i] << "\n";
        else cout << "INF\n";
    }
}