#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

typedef struct Edge {
	int u, v, w;
	bool operator > (const Edge& tmp) const {
		return w > tmp.w;
	}
} Edge;

vector<Edge> edges;
vector<int> parent;

// Union-Find 구현
int find(int a) {
	if(parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

void unionfunc(int a, int b) {
	a = find(a);
	b = find(b);

	if(a != b) { // 이미 연결된 노드가 아니라면
		parent[b] = a; // 연결
	}
}

// MST - edge 기준으로 처리하는 것이 특징

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n ,m;
	int a, b, c;
	// 오름차순 정렬 pq
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	cin >> n >> m;
	parent.resize(n+1);
	for(int i=0; i<=n; i++) {
		parent[i] = i;
	}
	for(int i=0; i<m; i++) {
		cin >> a >> b >> c;
		edges.push_back(Edge{a, b, c});
		pq.push(Edge{a, b, c});
	}

	int usedEdges = 0;
	int weightsum = 0;

	while(usedEdges < n-1) {
		Edge target = pq.top();
		pq.pop();
		// 간선이 잇는 두 정점이 아직 서로 연결되지 않았다면
		if(find(target.u) != find(target.v)) {
			unionfunc(target.u, target.v);
			usedEdges++;
			weightsum += target.w;
		} 
	}

	cout << weightsum;
}