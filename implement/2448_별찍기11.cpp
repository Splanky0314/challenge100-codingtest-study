#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
bool board[4000][8000];

void solve(int x, int y, int size) {
	if(size == 3) {
		board[x+2][y+2] = 1;
		board[x+1][y+1] = board[x+1][y+3] = 1;
		board[x][y] = board[x][y+1] = board[x][y+2] = board[x][y+3] = board[x][y+4] = 1;
		return;
	}

	solve(x+0, y+0, size/2); // left
	solve(x+0, y+size, size/2); // right
	solve(x+size/2, y+size/2, size/2); // up
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	if(n == 3) {
		solve(0, 0, n);
	}
	else {
		solve(0, 0, n/2); // left
		solve(0, n, n/2); // right
		solve(n/2, n/2, n/2); // up
	}

	for(int i=n-1; i>=0; i--) {
		for(int j=0; j<n*2; j++) {
			printf(board[i][j] ? "*":" ");
		} printf("\n");
	}
}