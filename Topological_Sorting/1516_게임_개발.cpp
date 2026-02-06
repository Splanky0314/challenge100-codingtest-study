#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, tmp;
	vector<vector<int>> g;
	vector<int> indegree;
	vector<int> time;

	cin >> n;
	g.resize(n+1);
	indegree.resize(n+1);
	time.resize(n+1);

	for(int i=1; i<=n; i++) {
		cin >> time[i];
		while(1) {
			cin >> tmp;
			if(tmp == -1) break;
			g[tmp].push_back(i);
			indegree[i]++;
		}
	}

	queue<int> q;
	int x;
	for(int i=1; i<=n; i++) {
		if(indegree[i] == 0) {
			q.push(i);
		}
	}
	int ans[501] = {0, };
	while(!q.empty()) {
		x = q.front();
		q.pop();
		for(int y: g[x]) {
			indegree[y]--;
			ans[y] = max(ans[y], ans[x]+time[x]);
			if(indegree[y] == 0) {
				q.push(y);
			}
		}
	}
	
	for(int i=1; i<=n; i++) {
		cout << ans[i]+time[i] << "\n";
	}
}