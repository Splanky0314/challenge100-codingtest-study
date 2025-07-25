#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

typedef struct vec {
	int x; int y;
} vec;

int n;
bool board[10000][10000];

// flag = 0 거꾸로
// flag = 1 그대로
void solve(int hei, int left, int right, bool flag) {
	// cout << hei << " " << left << " " << right << " " << flag << endl; // for test3
	if(left > right) return;
	if(left == right) {
		board[hei][left] = 1;
		return;
	}

	int len = (right - left) / 2 + 1;
	if(flag) { // 그대로
		for(int i=0; i<(right-left)/2 + 1; i++) {
			// 밑변
			board[hei][left + i] = 1; 
			board[hei][right - i] = 1;
			// 꼬깔
			board[hei - i][left + i] = 1;
			board[hei - i][right - i] = 1;
		}

		solve(hei - len/2, left+len/2 + 1, right-len/2 - 1, !flag);
	}
	else { // 거꾸로
		for(int i=0; i<(right-left)/2 + 1; i++) {
			// 밑변
			board[hei][left + i] = 1; 
			board[hei][right - i] = 1;
			// 꼬깔
			board[hei + i][left + i] = 1;
			board[hei + i][right - i] = 1;
		}

		solve(hei + len/2, left+len/2 + 1, right-len/2 - 1, !flag);
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	int w = 1; // calc w
	for(int i=1; i<n; i++) {
		w = w*2 + 3;
	}
	int h = (w+1)/2;

	solve(h, 1, w, 1);

	if(n%2) {
		for(int i=1; i<=h; i++) {
			for(int j=1; j<=w/2 + i; j++) {
				cout << (board[i][j] ? "*" : " ");
			} cout << "\n";
		}
	}
	else {
		for(int i=h; i>=1; i--) {
			for(int j=1; j<=w/2 + i; j++) {
				cout << (board[i][j] ? "*" : " ");
			} cout << "\n";
		}
	}
	
}