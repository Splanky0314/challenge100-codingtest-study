#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

vector<int> g[300001];
bool v[300001];
vector<int> ans;

void bfs(int x, int k) {
	queue<pair<int, int>> q;
	int depth;

	v[x] = 1;
	q.push({x, 0});
	while(!q.empty()) {
		x = q.front().first;
		depth = q.front().second;
		q.pop();

		if(depth == k) {
			ans.push_back(x);
			continue;
		}

		for(int y: g[x]) {
			if(!v[y]) {
				v[y] = 1;
				q.push({y, depth+1});
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k, x, a, b;
	cin >> n >> m >> k >> x;
	for(int i=0; i<m; i++) {
		cin >> a >> b;
		g[a].push_back(b);
	}

	bfs(x, k);

	if(ans.size() == 0) {
		cout << -1;
	}
	else {
		sort(ans.begin(), ans.end());
		for(int i=0; i<ans.size(); i++) {
			cout << ans[i] << "\n";
		}
	}
}