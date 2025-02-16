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

	int n;
	int tmp;
	cin >> n;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(i == j) dist[i][j] = 0;
			else dist[i][j] = 1000001;
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin >> tmp;
			if(tmp == 0) dist[i][j] = 1000001;
			else dist[i][j] = tmp;
		}
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
			if(dist[i][j] == 1000001)
				cout << "0 ";
			else cout << "1 ";
		} cout << "\n";
	}
}