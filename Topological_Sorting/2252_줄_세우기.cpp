#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, a, b;
	vector<int> indegree;
	vector<vector<int>> g;

	cin >> n >> m;
	indegree.resize(n+1);
	g.resize(n+1);

	// graph 정보, indegree 정보 받아오기
	for(int i=0; i<m; i++) {
		cin >> a >> b;
		g[a].push_back(b);
		indegree[b]++;
	}

	// 위상 정렬
	queue<int> q;
	int x;

	for(int i=1; i<=n; i++) {
		if(indegree[i] == 0) 
			q.push(i);
	}

	while(!q.empty()) {
		x = q.front();
		q.pop();
		cout << x << " ";
		for(int y: g[x]) {
			indegree[y]--;
			if(indegree[y] == 0) {
				q.push(y);
			}
		}
	}
}