#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

vector<int> g[10001];
int cnt[10001];
int v[10001];
int result[10001];

void bfs(int x) {
	queue<int> q;

	v[x] = 1;
	q.push(x);
	//cnt[x] = 1;
	while(!q.empty()) {
		x = q.front();
		q.pop();
		for(int y: g[x]) {
			if(!v[y]) {
				v[y] = 1;
				q.push(y);
				result[y]++;
				cnt[y] += cnt[x];
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, a, b;
	vector<int> ans;
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		cin >> a >> b;
		g[a].push_back(b);
	}

	int max = -1;
	// init
	for(int i=1; i<=n; i++) {
		cnt[i] = 1;
	}

	// bfs 시행
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) v[j] = 0;
		bfs(i);
		
	}
	// 최대 cnt(감염시킬 수 있는 컴퓨터 갯수) 찾기
	for(int i=1; i<=n; i++) {
		// cout << i << ": " << result[i] << endl;
		if(max == -1 || result[i] > max) {
			max = result[i];
		}
	}

	for(int i=1; i<=n; i++) {
		if(result[i] == max) {
			cout << i << " ";
		}
	}
}