#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	n--; m--;

	if(n > m) cout << m*m;
	else if(n < m) cout << n*n;
	else if(n == m) {
		cout << n*n - 2 * (n-1);
	}
}