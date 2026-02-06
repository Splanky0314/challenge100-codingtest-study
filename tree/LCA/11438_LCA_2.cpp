#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

int n, m;
vector<int> g[100001];
vector<int> dep;
int parent[100001][22];
bool v[100001];
int maxdep = -1;

void dfs(int x, int dept) {
	v[x] = 1;
	dep[x] = dept;
	if(maxdep < dept) maxdep = dept;
	for(int y: g[x]) {
		if(!v[y]) {
			parent[y][0] = x; 
			dfs(y, dept+1);
		}
	}
}

void set_parent() {
	for(int j=1; j<21; j++) {
		for(int i=1; i<=n; i++) {
			parent[i][j] = parent[parent[i][j-1]][j-1];
		}
	}
}

int lca(int a, int b) {
	// a랑 b의 depth 같게 맞추기!!
	// a가 dep가 크도록
	if(dep[a] < dep[b]) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	for(int k=21; k>=0; k--) {
		if(dep[a] - dep[b] >= (1 << k)) {
			if(dep[b] <= dep[parent[a][k]]) {
				a = parent[a][k];
			}
		}
	}
	
	
	// 공통 조상 찾기

	for(int i=21; i>=0 && a != b; i--) {
		if(parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	
	int LCA = a;
	if(a != b) {
		LCA = parent[LCA][0];
	}
	
	return LCA;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> n;

	dep.resize(n+1);
	dep.assign(n + 1, -1);
	for(int i=0; i<n-1; i++) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 0);
	// for test

	set_parent(); // 최대 k로 그냥 넣기

	// // for test
	// for(int i=1; i<n+1; i++) {
	// 	cout << i << ": ";
	// 	for(int j=0; j<4; j++) {
	// 		cout << parent[i][j] << " ";
	// 	} cout << "\n";
	// } cout << endl << endl;
	
	// cout << k << endl << endl; // for test

	cin >> m;
	for(int T=0; T<m; T++) {
		cin >> a >> b;
		cout << lca(a, b) << "\n";
	}
}