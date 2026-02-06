#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;
using ll = long long;

int n, m;
int dist[101][101];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int u, v, w;
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(i==j) dist[i][j] = 0;
			else dist[i][j] = 100000001;
		}
	}

	for(int i=0; i<m; i++) {
		cin >> u >> v >> w;
		if(dist[u][v] > w)
			dist[u][v] = w;
	}

	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(dist[i][j] == 100000001)
				cout << "0 ";
			else cout << dist[i][j] << " ";
		} cout << "\n";
	}
}