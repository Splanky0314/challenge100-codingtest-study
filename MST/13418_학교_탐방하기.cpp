#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

typedef struct Edge {
	int u, v, w;
	bool operator> (const Edge &tmp) const {
		return w > tmp.w;
	}
	bool operator< (const Edge &tmp) const {
		return w < tmp.w;
	}
} Edge;

int n, m;
priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
priority_queue<Edge, vector<Edge>, less<Edge>> pq2;
int parent[1001];

int find(int a) {
	if(parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

void unionfunc(int a, int b) {
	a = find(a); b = find(b);
	if(a != b) parent[b] = a;
}


int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	cin >> n >> m;
	for(int i=0; i<=m; i++) {
		cin >> a >> b >> c;
		pq.push(Edge {a, b, c});
		pq2.push(Edge {a, b, c});
	}

	// 최악
	int usedEdge = 0;
	int upstairs = 0;
	for(int i=0; i<=n; i++) parent[i] = i;
	while(usedEdge < n) {
		Edge tmp = pq.top();
		pq.pop();
		// cout << tmp.u << "->" << tmp.v << "=" << tmp.w << endl;
		if(find(tmp.u) != find(tmp.v)) {
			unionfunc(tmp.u, tmp.v);
			upstairs += (tmp.w == 0);
			usedEdge++;
		}
	}

	// 최선
	usedEdge = 0;
	int upstairs2 = 0;
	for(int i=0; i<=n; i++) parent[i] = i;
	while(usedEdge < n) {
		Edge tmp = pq2.top();
		pq2.pop();
		if(find(tmp.u) != find(tmp.v)) {
			unionfunc(tmp.u, tmp.v);
			upstairs2 += (tmp.w == 0);
			usedEdge++;
		}
	}
	
	// cout << upstairs << endl; //
	// cout << upstairs2 << endl; //
	cout << upstairs*upstairs - upstairs2*upstairs2;
}