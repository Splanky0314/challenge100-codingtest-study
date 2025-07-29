#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n, m;
vector<int> g[50001];
vector<int> dep;
vector<int> parent;
bool v[50001];

void dfs(int x, int dept) {
	// cout << x << " - " << dept << endl;
	v[x] = 1;
	dep[x] = dept;
	for(int y: g[x]) {
		if(!v[y]) {
			parent[y] = x;
			dfs(y, dept + 1);
		}
	}
}

int lca(int a, int b) {
	while(dep[a] > dep[b]) {
		a = parent[a];
	}
	while(dep[a] < dep[b]) {
		b = parent[b];
	}

	while(a != b) {
		a = parent[a];
		b = parent[b];
	}

	return a;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> n;
	dep.resize(n+1);
	parent.resize(n+1);
	for(int i=0; i<n-1; i++) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 0); // 1번 노드 : depth = 0

	// // for test
	// for(int i=0; i<n+1; i++) {
	// 	cout << parent[i] << "|";
	// } cout << endl << endl;

	cin >> m;
	for(int T=0; T<m; T++) {
		cin >> a >> b;
		cout << lca(a, b) << "\n";
	}
}