#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <tuple>

using namespace std;
using ll = long long;

typedef tuple<int,int,int> edge;
static int n, m;
static vector<edge> edges;
vector<long> dist;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	cin >> n >> m;
	dist.resize(n+1);
	fill(dist.begin(), dist.end(), LONG_MAX);

	for(int i=0; i<m; i++) {
		cin >> a >> b >> c;
		edges.push_back({a,b,c});
	}

	dist[1] = 0;

	for(int i=1; i<n; i++) { // n-1번 반복
		for(int j=0; j<m; j++) { // m만큼 반복
			edge medge = edges[j];
			int u = get<0>(medge);
			int v = get<1>(medge);
			int w = get<2>(medge);

			// dist 값이 INF가 아닌 정점에 연결된 경우에만 탐색 진행
			// (도달할 수 있는 정점이 연결된 간선에 대해서만 탐색)
			if(dist[u] != LONG_MAX && dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
			}
		}
	}

	// 음수 사이클 발생 체크
	bool mCycle = false;
	for(int i=0; i<m; i++) {
		edge medge = edges[i];
		int u = get<0>(medge);
		int v = get<1>(medge);
		int w = get<2>(medge);
		
		// dist가 갱신된다면, 음수 사이클이 존재하는 것
		if(dist[u] != LONG_MAX && dist[v] > dist[u] + w) {
			mCycle = true;
		}
	}

	if(!mCycle) {
		for(int i=2; i<=n; i++) {
			if(dist[i] == LONG_MAX) {
				cout << "-1\n";
			}
			else cout << dist[i] << "\n";
		}
	}
	else cout << -1;
}