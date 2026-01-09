#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;
using ll = long long;

int n, m;
string tmp, str[11];
int maxcnt = -1;
int minval = -1;

void solve(int idx, int sum, array<bool, 51> cur) {
	// for test
	// cout << idx << " " << sum << endl;
	// for(int i=0; i<n; i++) cout << v[i] << " ";
	// cout << endl;
	// for(int j=0; j<m; j++) cout << cur[j] << " ";
	// cout << endl;
	
	/////////////////////////////////////////////////////////////////////


		bool isused = false;
		for(int j=0; j<m; j++) {
			if(str[idx][j] == 'Y' && cur[j] == false) {
				cur[j] = true;
				isused = true;
			}
		}

		if(isused) sum++;
	
	
	for(int i=idx+1; i<n; i++) {
		solve(i, sum, cur); // i번기타 사용
	}

	int cnt = 0;
	for(int j=0; j<m; j++) {
		if(cur[j] == true) cnt++;
	}
	if(cnt == 0) return;
	if(maxcnt == -1 || maxcnt < cnt) {
		maxcnt = cnt;
		minval = sum;
	}
	else if(maxcnt == cnt) {		
		if(minval == -1 || minval > sum) {
			// cout << "FINISHED!!: " << minval << "/" << sum << endl;
			minval = sum; return;
		}	
	}	
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> tmp >> str[i];
	}

	for(int i=0; i<n; i++) {
		array<bool, 11> vv = {false, };
		array<bool, 51> curr = {false, };
		
		solve(i, 0, curr);
		solve(i, 0, curr);
	}
	cout << minval;
}