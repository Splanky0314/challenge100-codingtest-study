#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;
using ll = long long;

typedef struct Edge {
	int u, v, w;

	bool operator > (const Edge &tmp) const {
		return w > tmp.w;
	}
} Edge;

vector<Edge> edges;
priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
int parent[1001];

int find(int a) {
	if(parent[a] == a) return a;
	return find(parent[a]);
}	

void unionfunc(int a, int b) {
	a = find(a);
	b = find(b);
	if(a != b) parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int a, b, c;
	cin >> n >> m;
	for(int i=0; i<=n; i++) {
		parent[i] = i;
	}

	for(int i=0; i<m; i++) {
		cin >> a >> b >> c;
		edges.push_back(Edge {a, b, c}); // a == b 일 수도 있다.
		pq.push(Edge {a, b, c});
	}

	ll sum = 0;
	int usedEdge = 0;
	while(usedEdge < n-1) {
		Edge tmp = pq.top();
		pq.pop();
		if(find(tmp.u) != find(tmp.v)) {
			// cout << tmp.u << "->" << tmp.v << " : " << tmp.w << endl; // for test
			sum += tmp.w;
			unionfunc(tmp.u, tmp.v);
			usedEdge++;
		}
	}
	cout << sum;
}