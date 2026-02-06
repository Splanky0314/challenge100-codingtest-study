#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>

using namespace std;
using ll = long long;

vector<pair<int,int>> edges;
vector<int> dist;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, tmp;
	cin >> n;
	dist.resize(n+1);
	fill(dist.begin(), dist.end(), INT_MAX);
	for(int i=1; i<n; i++) {
		cin >> m;
		for(int j=1; j<=m; j++) {
			cin >> tmp;
			edges.push_back({i, tmp});
		}
	}

	dist[1] = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i=1; i<n; i++) {
		for(int j=0; j<edges.size(); j++) {
			int u = edges[j].first;
			int v = edges[j].second;
			
			if(dist[u] != INT_MAX && dist[v] > dist[u] + (-1)) {
				dist[v] = dist[u] + (-1); // 이어져만 있으면
			}
		}
	}

	bool cycle = false;
	for(int j=0; j<edges.size(); j++) {
		int u = edges[j].first;
		int v = edges[j].second;
		
		if(dist[u] != INT_MAX && dist[v] > dist[u] + (-1)) {
			cycle = true; // 이어져만 있으면
		}
	}

	if(cycle) cout << "CYCLE";
	else cout << "NO CYCLE";
}