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
} Edge;

priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
int parent[51];

int find(int a) {
	if(parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

void unionfunc(int a, int b) {
	a = find(a);
	b = find(b);
	if(a != b) parent[b] = a;
}

int returnlength(char tmp) {
	if(tmp == '0') return -1;
	if('a' <= tmp && tmp <= 'z') {
		return tmp - 'a' + 1;
	}
	else {
		return tmp - 'A' + 27;
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, length;
	char tmp;
	ll lensum = 0;
	cin >> n;
	for(int i=0; i<=n; i++) parent[i] = i;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> tmp;
			if((length = returnlength(tmp)) != -1) {
				pq.push({i, j, length});
				lensum += length;
				// cout << i << " -> " << j << " = " << length << endl; //
			}			
		}
	}
	// cout << endl << endl; //

	int usedEdge = 0;
	while(usedEdge < n-1) {
		if(pq.empty()) {
			lensum = -1;
			break;
		}
		Edge e = pq.top();
		pq.pop();
		if(find(e.u) != find(e.v)) {
			// cout << e.u << " -> " << e.v << " = "<< e.w << endl; //
			unionfunc(e.u, e.v);
			usedEdge++;
			lensum -= e.w;
		}
	}

	cout << lensum;
}