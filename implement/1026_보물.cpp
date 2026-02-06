#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<int> a;
	vector<int> b;

	cin >> n;
	a.resize(n);
	b.resize(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	for(int i=0; i<n; i++) {
		cin >> b[i];
	}

	ll sum = 0;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for(int i=0; i<n; i++) {
		sum += a[i]*b[n-i-1];
	}
	cout << sum;
}