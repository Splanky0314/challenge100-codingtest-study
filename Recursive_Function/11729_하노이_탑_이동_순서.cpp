#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;

vector<pair<int,int>> ans;

int hanoi(int n, int a, int b, int c) {
	if(n == 1) {
		// cout << a << " " << b << "\n";
		ans.push_back({a, b});
		return 1;
	}

	int sum = 1;
	sum += hanoi(n-1, a, c, b);
	// cout << a << " " << c << "\n";
	ans.push_back({a, b});
	sum += hanoi(n-1, c, b, a);
	return sum;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 23:23

	int n;
	cin >> n;
	cout << hanoi(n, 1, 3, 2) << "\n";
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
}