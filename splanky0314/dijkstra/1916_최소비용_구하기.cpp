#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;
using ll = long long;

vector<bool> visited;
vector<int> dist;
vector<vector<pair<int,int>>> g;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, a, b;
	int u, v, w;
	cin >> n >> m;
	visited.resize(n+1);
	fill(visited.begin(), visited.end(), false);
	dist.resize(n+1);
	fill(dist.begin(), dist.end(), INT_MAX);
	g.resize(n+1);

	for(int i=0; i<m; i++) {
		cin >> u >> v >> w;
		g[u].push_back({v, w});
	}
	cin >> a >> b;

	int target = a;
	dist[target] = 0;
	q.push({dist[target], target});
	while(!q.empty()) {
		pair<int, int> tmp = q.top();
		target = tmp.second;
		q.pop();
		if(visited[target]) continue;
		visited[target] = true;
		for(pair<int, int> tmp: g[target]) {
			v = tmp.first;
			w = tmp.second;
			if(dist[v] > dist[target] + w) {
				dist[v] = dist[target] + w;
				q.push({dist[v], v});
			}
		}
		// for test
		// for(int i=1; i<=n; i++) {
		// 	cout << dist[i] << " ";
		// } cout << endl;
	}

	cout << dist[b];
}