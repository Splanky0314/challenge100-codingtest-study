#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <limits.h>
#include <queue>

using namespace std;
using ll = long long;

typedef tuple<int,int,int> edge;

int N, M, A, B;
vector<edge> edges;
vector<long long> dist;
vector<bool> visited;
vector<int> cyclenode;

bool dfs2(int x, int dst) {
	int u, v, w;
	visited[x] = true;
	if(x == dst) return true;

	for(int j=0; j<M; j++) {
		u = get<0>(edges[j]);
		v = get<1>(edges[j]);
		w = get<2>(edges[j]);
		if(u == x && visited[v] == false) {
			if(dfs2(v, dst)) return true;
		}
	}
	return false;
}


int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int u, v, w, prof;
	vector<int> profit;
	cin >> N >> A >> B >> M;
	dist.resize(N+1);
	cyclenode.resize(N+1);
	visited.resize(N+1);
	fill(dist.begin(), dist.end(), LLONG_MAX);
	fill(cyclenode.begin(), cyclenode.end(), false);
	
	for(int i=0; i<M; i++) {
		cin >> u >> v >> w;
		edges.push_back({u,v,w});
	}
	for(int i=0; i<N; i++) {
		cin >> prof;
		profit.push_back(prof);
	}

	// profit 고려해서 edges의 가중치 수정
	for(int i=0; i<M; i++) {
		get<2>(edges[i]) -= profit[get<1>(edges[i])];
	}

	dist[A] = -profit[A];
	for(int i=0; i<N-1; i++) {
		for(int j=0; j<M; j++) {
			u = get<0>(edges[j]);
			v = get<1>(edges[j]);
			w = get<2>(edges[j]);
			if(dist[u]!=LLONG_MAX && dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
			}
		}
	}

	bool cycle = false; // cycle 존재하면 돈 무한히 벌기 가능
	for(int j=0; j<M; j++) {
		u = get<0>(edges[j]);
		v = get<1>(edges[j]);
		w = get<2>(edges[j]);
		if(dist[u]!=LLONG_MAX && dist[v] > dist[u] + w) {
			cycle = true;
			if(cyclenode[u] || cyclenode[v]) {
				cyclenode[u] = true;
				cyclenode[v] = true;
				continue;
			}
			
			// 음수 사이클이 A -> B 사이에 존재하는 경우
			// cout << "searchcycle: " << v << " " << B << endl; // for test
			fill(visited.begin(), visited.end(), false);
			if(dfs2(v, B)) {
				fill(visited.begin(), visited.end(), false);
				if(dfs2(A, v)) {
					cout << "Gee";
					return 0;
				}
			}
		}
	}

	// for test
	// for(int i=0; i<N; i++) {
	// 	cout << cyclenode[i] << " ";
	// } cout << endl;

	// 음수사이클이 A -> B 경로 사이에 존재하는지 확인
	if(dist[B] == LLONG_MAX) cout << "gg";
	else cout << -dist[B];
}