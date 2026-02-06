#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

typedef struct pos {
	int x, y;
} pos;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 2/2 23:00
	int T; pos p1, p2; int r1, r2;
	cin >> T;
	for(int t=0; t<T; t++) {
		cin >> p1.x >> p1.y >> r1;
		cin >> p2.x >> p2.y >> r2;
		
		int sqared_dist = (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
		if(p1.x == p2.x && p1.y == p2.y) {
			if(r1 == r2) cout << -1 << "\n";
			else cout << 0 << "\n";
		}
		else if((r1+r2)*(r1+r2) < sqared_dist) {
			cout << 0 << "\n"; 
		}
		else if((r1 + sqrt(sqared_dist) < r2)) {
			cout << 0 << "\n";
		}
		else if((r2 + sqrt(sqared_dist) < r1)) {
			cout << 0 << "\n";
		}
		else if((r1+r2)*(r1+r2) == sqared_dist) {
			cout << 1 << "\n"; 
		}
		else if((r1-r2)*(r1-r2) == sqared_dist) {
			cout << 1 << "\n"; 
		}
		else if((r1+r2)*(r1+r2) > sqared_dist) {
			cout << 2 << "\n";
		}
	}
}