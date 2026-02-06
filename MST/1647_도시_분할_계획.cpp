#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

typedef struct Edge {
	int u, v, w;
	// 왼쪽 피연산자는 반드시 해당 구조체의 객체여야.
	// 오른쪽 피연산자는 함수의 parameter로 전달됨
	// 왼쪽 피연산자 > 오른쪽 피연산자 인 경우 true
	bool operator > (const Edge &tmp) const { // greater
		return w > tmp.w;
	}
} Edge;

vector<Edge> edges;
priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
int parent[100001];

int find(int a) {
	if(parent[a] == a) return a;
	return parent[a] = find(parent[a]);
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
	for(int i=0; i<=n; i++) parent[i] = i;
	for(int i=0; i<m; i++) {
		cin >> a >> b >> c; // 양방향 간선, 유지비
		edges.push_back(Edge {a, b, c});
		pq.push(Edge {a, b, c});
	}

	int usedEdge = 0;
	ll sum = 0;
	int maxwei = -1;
	while(usedEdge < n-1) {
		Edge tmp = pq.top();
		pq.pop();
		if(find(tmp.u) != find(tmp.v)) {
			unionfunc(tmp.u, tmp.v);
			usedEdge++;
			sum += tmp.w;
			if(maxwei < tmp.w) {
				maxwei = tmp.w;
			}
		}
	}

	cout << sum - maxwei;
}