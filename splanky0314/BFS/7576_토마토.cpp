#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;


int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};

int map[1001][1001];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int m, n;
	queue<pair<int,int>> q;
	
	cin >> m >> n;
	for(int i=0; i<n; i++) 
		for(int j=0; j<m; j++) {
			cin >> map[i][j];
			if(map[i][j] == 1) q.push({i, j});
		} 
		
	int x, y, color;
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		color = map[x][y];

		for(int k=0; k<4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if(0<=nx&&nx<n&&0<=ny&&ny<m&&map[nx][ny] == 0) {
				map[nx][ny] = color+1;
				q.push({nx, ny});
			}
		}
	}

	// // for test
	// for(int i=0; i<n; i++) {
	// 	for(int j=0; j<m; j++) {
	// 		cout << map[i][j] << " ";
	// 	} cout << endl;
	// } cout << endl;

	int maxval = -1;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(map[i][j] == 0) {
				cout << -1; return 0;
			}
			if(maxval < map[i][j]) {
				maxval = map[i][j];
			}
		}
	}	

	cout << maxval - 1;
}