#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n, m, a, b;
	cin >> T;
	for(int t=0; t<T; t++) {
		cin >> n >> m;
		for(int i=0; i<m; i++) {
			cin >> a >> b;
		}
		cout << n-1 << "\n";
	}
}