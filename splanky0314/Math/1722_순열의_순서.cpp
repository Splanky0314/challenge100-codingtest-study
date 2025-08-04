#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll n, k;
ll facto[21];
bool num[21];

int smallval_cnt(int x) {
	int result = 0;
	for(int i=1; i<x; i++) {
		if(!num[i]) result++;
	}
	return result;
}

int find_smallval(int x) {
	for(int i=1; i<=n; i++) {
		if(!num[i]) {
			if(x == 1) return i;
			x--;
		}
	}
	return -1; // warning떠서..
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int option;
	cin >> n >> option;

	// calc facto[]
	facto[0] = 1;
	for(int i=1; i<=n; i++) {
		facto[i] = facto[i-1] * i;
	}

	if(option == 1) {
		int quot;
		int smallval;
		cin >> k;
		k--;
		for(int i=0; i<n; i++) {
			quot = k / facto[n-i-1];
			k %= facto[n-i-1];

			smallval = find_smallval(quot + 1);
			num[smallval] = true;
			cout << smallval << " ";
		}
	}
	else if(option == 2) {
		ll ans = 0;
		int inputval;

		for(int i=0; i<n; i++) {
			cin >> inputval;
			ans += facto[n-i-1] * (smallval_cnt(inputval));
			num[inputval] = true;
		}

		cout << ans + 1;
	}

}