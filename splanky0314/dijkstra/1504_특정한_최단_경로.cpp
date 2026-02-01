#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2147483647

using namespace std;
using ll = long long;

int n, e, n1, n2;
vector<pair<int,int>> g[801];
bool v[801];
int dist[801];

int dijkstra(int x, int dest) {
	for(int i=1; i<=n; i++) {
		dist[i] = INF; v[i] = false;
	}
	dist[x] = 0; v[x] = true;

	while(true) {
		if(x == dest) return dist[x];

		// for test
		for(int i=1; i<=n; i++) cout << dist[i] << " ";
		cout << endl;

		for(pair<int,int> tmp: g[x]) {
			if(dist[tmp.first] > dist[x] + tmp.second) {
				dist[tmp.first] = dist[x] + tmp.second;
			}
		}

		// for test
		for(int i=1; i<=n; i++) cout << dist[i] << " ";
		cout << endl;

		int minidx, minval = -1;
		for(int i=1; i<=n; i++) {
			if(!v[i] && (minval == -1 || minval > dist[i])) {
				minidx = i; minval = dist[i];
			}
		}
		if(minval == -1 || minval == INF) return -1;
		v[minidx] = true;
		x = minidx;
	}

	return -1;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	int a, b, c;
	cin >> n >> e;
	for(int i=0; i<e; i++) {
		cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	} cin >> n1 >> n2;

	int tmp, result1 = 0, result2 = 0;
	if((tmp = dijkstra(1, n1)) != -1) {
		result1 += tmp;
		if((tmp = dijkstra(n1, n2)) != -1) {
			result1 += tmp;
			if((tmp = dijkstra(n2, n)) != -1) {
				result1 += tmp;
			} else result1 = -1;
		} else result1 = -1;
	} else result1 = -1;

	if((tmp = dijkstra(1, n2)) != -1) {
		result2 += tmp;
		if((tmp = dijkstra(n2, n1)) != -1) {
			result2 += tmp;
			if((tmp = dijkstra(n1, n)) != -1) {
				result2 += tmp;
			} else result2 = -1;
		} else result2 = -1;
	} else result2 = -1;

	// cout << result1 << " " << result2;
	if(result1 == -1) cout << result2;
	else if(result2 == -1) cout << result1;
	else if(result1 < result2) cout << result1;
	else cout << result2;
}