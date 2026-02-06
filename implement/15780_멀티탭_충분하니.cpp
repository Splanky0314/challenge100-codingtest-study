#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, a[101];
	int avail = 0;
	cin >> n >> k;
	for(int i=0; i<k; i++) {
		cin >> a[i];
		avail += (a[i]+1)/2;
	}

	if(avail >= n) cout << "YES";
	else cout << "NO";
}