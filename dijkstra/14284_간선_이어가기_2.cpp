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

	int n, m, s, t;
	int a, b, c;
	cin >> n >> m;
	visited.resize(n+1);
	fill(visited.begin(), visited.end(), false);
	dist.resize(n+1);
	fill(dist.begin(), dist.end(), INT_MAX);
	g.resize(n+1);

	for(int i=0; i<m; i++) {
		cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	cin >> s >> t;

	int target = s;
	dist[target] = 0;
	q.push({dist[target], target});
	while(!q.empty()) {
		target = q.top().second;
		q.pop();
		if(visited[target]) continue;
		visited[target] = true;
		for(pair<int,int> tmp: g[target]) {
			int v = tmp.first;
			int w = tmp.second;
			if(dist[v] > dist[target] + w) {
				dist[v] = dist[target] + w;
				q.push({dist[v], v});
			}
		}
	}

	cout << dist[t];
}