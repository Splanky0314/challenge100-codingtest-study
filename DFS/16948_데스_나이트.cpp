#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int dx[] = {-2, -2, 0, 0, 2, 2};
int dy[] = {-1, +1, -2, +2, -1, +1};

int n, r1, c1, r2, c2;
int v[201][201];
int minval = -1;

void dfs(int x, int y, int cnt) {
	if(x == r2 && y == c2) {
		if(minval == -1 || minval > cnt) {
			minval = cnt; return;
		}
	}

	for(int k=0; k<6; k++) {
		int nx = x + dx[k], ny = y + dy[k];
		if(0<=nx && nx<n && 0<=ny && ny<n && (v[nx][ny] == 0 || v[nx][ny] > cnt+1)) {
			v[nx][ny] = cnt+1;;
			dfs(nx, ny, cnt+1);
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 2/1 21:29
	
	cin >> n;
	cin >> r1 >> c1 >> r2 >> c2;

	dfs(r1, c1, 0);

	cout << minval;
}