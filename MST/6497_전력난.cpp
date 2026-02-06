#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

typedef struct Edge {
	int u, v, w;
	bool operator>(const Edge &tmp) const {
		return w > tmp.w;
	}
} Edge;

vector<Edge> edges(200001);
priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
int parent[200001];

int find(int a) {
	if(parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

void unionfunc(int a, int b) {
	a = find(a);
	b = find(b);
	if(a != b) {
		parent[b] = a;
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int a, b, c;
	ll total;
	while(true) {
		total = 0;
		cin >> n >> m;
		if(n == 0 && m == 0) return 0;
		while(!pq.empty()) pq.pop();
		fill(edges.begin(), edges.end(), Edge{0,0,0});
		for(int i=0; i<=n; i++) {
			parent[i] = i;
		}
		
		for(int i=0; i<m; i++) {
			cin >> a >> b >> c;
			total += c;
			edges[i] = Edge {a, b, c};
			pq.push(Edge {a, b, c});
		} 

		int usedEdge = 0;
		while(usedEdge < n-1) {
			Edge tmp = pq.top();
			pq.pop();
			if(find(tmp.u) != find(tmp.v)) {
				total -= tmp.w;
				usedEdge++;
				unionfunc(tmp.u, tmp.v);
			}
		}

		cout << total << "\n";
	} 
	
}