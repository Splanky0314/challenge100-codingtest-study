#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

vector<vector<int>> tree;
vector<int> ans;
vector<bool> visited;

void dfs(int x) {
	visited[x] = true;
	for(int y: tree[x]) {
		if(!visited[y]) {
			ans[y] = x; // 부모 노드 저장
			dfs(y);
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, a, b;
	cin >> n;
	tree.resize(n+1);
	ans.resize(n+1);
	visited.resize(n+1);
	for(int i=1; i<n; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1);

	for(int i=2; i<=n; i++) {
		cout << ans[i] << "\n";
	}
}