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
	int a, b, min1 = -1, min6 = -1;

	cin >> n >> m;
	for(int i=0; i<m; i++) {
		cin >> a >> b;
		if(min6 == -1 || min6 > a) min6 = a;
		if(min1 == -1 || min1 > b) min1 = b;
	}

	// package로 사는 게 이득인 경우,
	if(min1 * 6 >= min6) {
		int result1 = min6 * (n/6) + min1 * (n%6);
		int result2 = min6 * ((n+5)/6);
		cout << (result1 < result2 ? result1 : result2); 
	}
	else {
		cout << n * min1;
	}
}