#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;



int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cout << fixed;
	cout.precision(10);

	int n, m, k;
	cin >> n >> m >> k;

	double ans = 1.0;
	for(int i=0; i<k; i++) {
		ans = ans * double(n-m-i) / (n-i);
		cout << 1 - ans << "\n";
	}

}