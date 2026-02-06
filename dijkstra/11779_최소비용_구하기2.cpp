#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>

using namespace std;
using ll = long long;

vector<bool> visited;
vector<pair<int,int>> dist; // 최소비용값, previous node
vector<pair<int,int>> g[1001];
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
	fill(dist.begin(), dist.end(), make_pair(INT_MAX, 0));

	for(int i=0; i<m; i++) {
		cin >> u >> v >> w;
		g[u].push_back({v, w});
	}
	cin >> a >> b;

	int target = a, bef = 0;
	dist[target] = {0, 0};
	q.push({dist[target].first, target});
	while(!q.empty()) {
		target = q.top().second;
		q.pop();
		if(target == b) break;
		if(visited[target]) continue;
		visited[target] = true;
		for(pair<int,int> tmp: g[target]) {
			v = tmp.first;
			w = tmp.second;
			if(dist[v].first > dist[target].first + w) {
				dist[v] = {dist[target].first + w, target};
				q.push({dist[v].first, v});
			}
		}
	}

	cout << dist[b].first << "\n";
	vector<int> ans;
	target = b;
	while(target != 0) {
		ans.push_back(target);
		target = dist[target].second;
	}
	cout << ans.size() << "\n";
	for(int i=ans.size()-1; i>=0; i--) {
		cout << ans[i] << " ";
	}
}