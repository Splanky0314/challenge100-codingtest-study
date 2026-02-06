#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

typedef struct node {
	int a;
	int b;
	int c;
} node;

int a, b, c;
bool v[201][201][201];
bool ansv[201];
vector<int> ans;

// nx -> ny
void renew(int dx, int dy, int tar, int &nx, int &ny) {
	ny = dx+dy > tar ? tar : dx+dy;
	nx = dx+dy > tar ? dx+dy-tar : 0;
}


void bfs(int x) {
	queue<node> q;
	int na, nb, nc, tmp;
	int da, db, dc;

	v[0][0][x] = 1;
	q.push({0, 0, x});
	while(!q.empty()) {
		da = q.front().a;
		db = q.front().b;
		dc = q.front().c;
		q.pop();

		// cout << endl << "main: " << da << " " << db << " " << dc << endl;
		if(da == 0 && !ansv[dc]) {
			ansv[dc] = 1;
			ans.push_back(dc);
		}
		for(int k=0; k<6; k++) {
			switch (k) {
				case 0:
					renew(da, db, b, na, nb); nc = dc; break;
				case 1:
					renew(db, dc, c, nb, nc); na = da; break;
				case 2: 
					renew(dc, da, a, nc, na); nb = db; break;
				case 3:
					renew(db, da, a, nb, na); nc = dc; break;
				case 4:
					renew(dc, db, b, nc, nb); na = da; break;
				case 5:
					renew(da, dc, c, na, nc); nb = db; break;
			}
			if(!v[na][nb][nc]) {
				// cout << na << " " << nb << " " << nc << endl;
				v[na][nb][nc] = 1;
				q.push({na, nb, nc});
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> a >> b >> c;

	bfs(c);

	sort(ans.begin(), ans.end());
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
}