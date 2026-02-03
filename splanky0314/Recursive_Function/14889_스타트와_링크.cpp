#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
int s[21][21];
int mem[21];

int calc_diff() {
	int score[2] = {};
	for(int i=0; i<n; i++) {
		int team = mem[i];
		for(int j=i+1; j<n; j++) {
			if(team == mem[j]) score[team] += s[i][j];
		}
	}

	// // for test
	// for(int i=0; i<n; i++) cout << mem[i] << " ";
	// cout << endl;
	// cout << score[0] << " " << score[1] << " abs:" << abs(score[0] - score[1]) << endl;
	return abs(score[0] - score[1]);
}

int make_team(int idx, int cnt) {
	if(cnt == n/2) return calc_diff();
	if(idx >= n) return -1;

	int result1 = make_team(idx+1, cnt);
	mem[idx] = 1;
	int result2 = make_team(idx+1, cnt+1);
	mem[idx] = 0;
	
	if(result1 == -1) return result2;
	else if(result2 == -1) return result1;
	return min(result1, result2);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 2/3 16:00
	int tmp;

	cin >> n;
	for(int i=0; i<n; i++) 
		for(int j=0; j<n; j++) {
			cin >> tmp;
			if(i <= j) s[i][j] += tmp;
			else s[j][i] += tmp;
		}
			
	// // for test
	// cout << endl;
	// for(int i=0; i<n; i++) {
	// 	for(int j=0; j<n; j++) {
	// 		cout << s[i][j] << " ";
	// 	} cout << endl;
	// } cout << endl;

	cout << make_team(0, 0);
}