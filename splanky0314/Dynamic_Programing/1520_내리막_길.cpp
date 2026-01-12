#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <tuple>

using namespace std;
using ll = long long;

typedef struct elem {
	ll val;
	int x, y;

	bool operator<(const elem& other) const {
		return val < other.val;
	}
} elem;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, m;
int map[501][501] = {};
int dp[501][501] = {};
bool v[501][501] = {};

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin >> map[i][j];
		}
	}
	
	priority_queue<elem> q;
	dp[1][1] = 1;
	q.push({map[1][1],1,1});
	while(!q.empty()) {
		int x = q.top().x;
		int y = q.top().y;
		q.pop();

		if(v[x][y]) continue;
		v[x][y] = true;
		
		for(int k=0; k<4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if(1 <= nx && nx <=n && 1 <= ny && ny <=m) {
				if(map[x][y] > map[nx][ny]) { // 작은 것들
					dp[nx][ny] += dp[x][y];
					q.push({map[nx][ny], nx, ny});
				}
			}
		}
	}

	// // for test 
	// for(int i=1; i<=n; i++) {
	// 	for(int j=1; j<=m; j++) {
	// 		cout << dp[i][j] << " ";
	// 	} cout << endl;
	// } cout << endl;

	cout << dp[n][m];
}