#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

typedef struct pos {
	int x; int y;
} pos;

int n;
int map[101][101];
ll dp[101][101];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> map[i][j];
		}
	}

	dp[0][0] = 1;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(dp[i][j]) {
				if(i == n-1 && j == n-1) break;
				int jump = map[i][j];
				if(i+jump < n) {
					dp[i+jump][j] += dp[i][j];
				}
				if(j+jump < n) {
					dp[i][j+jump] += dp[i][j];
				}
			}
		}
	}

	// // for test
	// for(int i=0; i<n; i++) {
	// 	for(int j=0; j<n; j++) {
	// 		cout << dp[i][j] << " ";
	// 	} cout << endl;
	// } cout << endl;

	cout << dp[n-1][n-1];

	// map[n-1][n-1] = 100;

	// queue<pos> q;
	// q.push({0, 0});
	// while(!q.empty()) {
	// 	pos tmp = q.front();
	// 	// cout << tmp.x << " " << tmp.y << endl; // for test
	// 	q.pop();

	// 	int jump = map[tmp.x][tmp.y];
	// 	if(tmp.x + jump < n) {
	// 		dp[tmp.x+jump][tmp.y]++;
	// 		q.push({tmp.x+jump, tmp.y});
	// 	}
	// 	if(tmp.y + jump < n) {
	// 		dp[tmp.x][tmp.y+jump]++;
	// 		q.push({tmp.x, tmp.y+jump});
	// 	}
	// }
}