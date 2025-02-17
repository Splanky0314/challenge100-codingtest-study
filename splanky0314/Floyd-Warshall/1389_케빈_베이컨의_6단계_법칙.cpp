#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int dist[101][101];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int a, b;
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(i == j) dist[i][j] = 0;
			else dist[i][j] = 100000; 
		}
	}

	for(int i=0; i<m; i++) {
		cin >> a >> b; // 양방향 간선, 항상 연결그래프
		dist[a][b] = 1;
		dist[b][a] = 1;
	}

	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int minidx = -1;
	int minval = -1;
	for(int i=1; i<=n; i++) {
		int sum = 0;
		for(int j=1; j<=n; j++) {
			sum += dist[i][j];
		}
		if(minidx == -1 || minval > sum) {
			minidx = i;
			minval = sum;
		}
	}

	cout << minidx;
}