#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
bool map[1002][1002] = {};

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 14:28 ~ 14:47 : 19min
	
	char tmp;
	cin >> n;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin >> tmp;
			if(tmp == '*') map[i][j] = true;
			else map[i][j] = false;
		}
	}

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			// heart
			if(map[i-1][j] && map[i+1][j] && map[i][j-1] && map[j+1]) {
				cout << i << " " << j << "\n";

				int x, y, cnt;
				// left arm
				y = j-1; cnt = 0;
				while(0 < y) {
					if(map[i][y]) {
						cnt++;
						y--;
					}
					else break;
				}
				cout << cnt << " ";

				// right arm
				y = j+1; cnt = 0;
				while(y <= n) {
					if(map[i][y]) {
						cnt++;
						y++;
					}
					else break;
				}
				cout << cnt << " ";

				// 허리
				x = i+1; cnt = 0;
				while(x <= n) {
					if(map[x][j]) {
						cnt++; x++;
					}
					else break;
				}
				cout << cnt << " ";

				// left leg
				int xx;
				xx = x; y = j-1; cnt = 0;
				while(xx <= n) {
					if(map[xx][y]) {
						cnt++; xx++;
					}
					else break;
				}
				cout << cnt << " ";

				// right leg
				xx = x; y = j+1; cnt = 0;
				while(xx <= n) {
					if(map[xx][y]) {
						cnt++; xx++;
					}
					else break;
				}
				cout << cnt;
				return 0;
			} 
		}
	}
}