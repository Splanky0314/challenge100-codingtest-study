#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

typedef struct Pos {
	int x, y; 
} Pos;

int n, m;
vector<Pos> chicks;
vector<Pos> houses;
vector<bool> open;

int dist(Pos a, Pos b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int total_dist() {
	int sum = 0;
	for(int i=0; i<houses.size(); i++) {
		int minval = -1;
		for(int j=0; j<chicks.size(); j++) {
			if(open[j] == false) continue;

			int result = dist(houses[i], chicks[j]);
			if(minval == -1 || minval > result) minval = result;
		}
		sum += minval;
	}

	// // for test
	// for(int i=0; i<chicks.size(); i++) cout << open[i] << " ";
	// cout << endl << sum << endl;


	return sum;
}

int set_open(int idx, int cnt) {
	if(cnt == m) return total_dist();
	if(idx >= chicks.size()) return -1;

	int result1 = set_open(idx+1, cnt);
	open[idx] = true;
	int result2 = set_open(idx+1, cnt+1);
	open[idx] = false;

	if(result1 == -1) return result2;
	if(result2 == -1) return result1;
	return min(result1, result2);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 2/4 2:00
	int tmp;

	cin >> n >> m;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> tmp;
			if(tmp == 1) houses.push_back({i, j}); 
			else if(tmp == 2) chicks.push_back({i, j}); 
		}
	}
	open.resize(chicks.size());

	cout << set_open(0, 0);

}