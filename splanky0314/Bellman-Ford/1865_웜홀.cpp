#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <tuple>

using namespace std;
using ll = long long;

typedef tuple<int,int,int> edge;

int N, M, W, TC;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int u, v, w;
	cin >> TC;

	for(int t=0; t<TC; t++) {
		vector<edge> edges;
		vector<long> dist;
		// cout << "testcase: " << t << endl; // for test
		cin >> N >> M >> W;
		dist.resize(N+1);
		fill(dist.begin(), dist.end(), LONG_MAX);
		for(int i=0; i<M; i++) {
			cin >> u >> v >> w;
			edges.push_back({u, v, w});
			edges.push_back({v, u, w});
		}
		for(int i=0; i<W; i++) {
			cin >> u >> v >> w;
			edges.push_back({u, v, (-1)*w});
		}
		// 가상의 0번 노드와 모든 정점 연결하기
		for(int i=1; i<=N; i++) {
			edges.push_back({0, i, 0});
		}
		
		bool checkCycle = false;	
		dist[0] = 0; // 가상의 0번 노드를 시작으로
		for(int i=0; i<N; i++) {
			for(int j=0; j<edges.size(); j++) {
				edge tmp = edges[j];
				u = get<0>(tmp);
				v = get<1>(tmp);
				w = get<2>(tmp);

				if(dist[u]!=LONG_MAX && dist[v] > dist[u] + w) {
					dist[v] = dist[u] + w;
				}
			}
		}

		// 음수사이클 존재? -> 무조건 YES
		for(int j=0; j<edges.size(); j++) {
			edge tmp = edges[j];
			u = get<0>(tmp);
			v = get<1>(tmp);
			w = get<2>(tmp);

			if(dist[u]!=LONG_MAX && dist[v] > dist[u] + w) {
				// cout << "negative cycle!!" << endl; // for test
				checkCycle = true;
				break;
			}
		}		
		if(checkCycle == true) cout << "YES\n";
		else cout << "NO\n";
	}
}