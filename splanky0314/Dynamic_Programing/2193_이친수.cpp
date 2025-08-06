#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
ll z[91], x[91];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	z[1] = 0; x[1] = 1;
	for(int i=2; i<=n; i++) {
		z[i] = x[i-1] + z[i-1];
		x[i] = z[i-1];
	}
	cout << z[n] + x[n];
}