#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
bool board[3000][3000];	

void solve(int x, int y, int size) {
	if(size == 1) {
		// for(int i=0; i<3; i++) {
		// 	for(int j=0; j<3; j++) {
		// 		if(i==1 && j==1) continue;
		// 		board[x+i][y+j] = 1;
		// 	}
		// }
		board[x][y] = 1;
		return;
	}

	// 3 * 3 재귀 호출
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			if(i==1 && j==1) continue;
			solve(x+size/3*i, y+size/3*j, size/3);
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> n;

	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			if(i==1 && j==1) continue;
			solve(n/3*i, n/3*j, n/3);
		}
	}

	// print result
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			printf(board[i][j] ? "*" : " ");
		} printf("\n");
	}
}