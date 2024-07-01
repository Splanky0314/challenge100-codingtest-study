#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

vector<int> g[20001];
int set[20001];

bool bfs(int x) {
	queue<int> q;

	set[x] = 0;
	q.push(x);

	while(!q.empty()) {
		x = q.front();
		q.pop();
		for(auto y: g[x]) {
			if(set[y] == -1) {
				set[y] = 1 - set[x];
				q.push(y);
			}
			else if(set[x] == set[y]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n, e, a, b;
	bool isbin;

	cin >> T;
	for(int t=0; t<T; t++) {
		cin >> n >> e;
		// init
		isbin = true;
		for(int i=1; i<=n; i++) {
			set[i] = 0;
			g[i].clear();
			//vector<int>().swap(g[i]);
		}

		// save graph information
		for(int i=0; i<e; i++) {
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
			set[a] = -1;
			set[b] = -1;
		}

		for(int i=0; i<n; i++) {
			if(set[i] == -1) {
				if(bfs(i) == false) {
					isbin = false;
					break;
				}
			}
		}

		if(isbin) cout << "YES\n";
		else cout << "NO\n";
	}
}