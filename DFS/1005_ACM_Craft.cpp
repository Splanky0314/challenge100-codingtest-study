#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n, k, w;
int tcost[1001];
vector<int> g[1001];
int v[1001];

int dfs(int x) {
	if(v[x] != -1) return v[x];
	int maxval = -1;

	for(int y: g[x]) {
		if(v[y] != -1) maxval = max(maxval, v[y]); // dfs() 호출 최소화
		else maxval = max(maxval, dfs(y));
	}
	
	if(maxval == -1) return v[x] = tcost[x];
	return v[x] = maxval + tcost[x];
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 2/3 00:20
	int T; int a, b;
	
	cin >> T;
	for(int t=0; t<T; t++) {
		cin >> n >> k;
		for(int i=0; i<=n; i++) {
			g[i].clear(); v[i] = -1;
		}

		for(int i=1; i<=n; i++) cin >> tcost[i];
		for(int i=0; i<k; i++) {
			cin >> a >> b;
			g[b].push_back(a); // 거꾸로 가자!
		}
		cin >> w;

		cout << dfs(w) << "\n";

		// // for test
		// for(int i=1; i<=n; i++) {
		// 	cout << v[i] << " ";
		// } cout << endl;
	}
}