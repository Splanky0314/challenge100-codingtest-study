#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, a, b;
	int cnt = 0;
	cin >> n >> a >> b;
	
	while(a != b) {
		a = (a+1) / 2;
		b = (b+1) / 2;
		cnt++;
	}

	cout << cnt;
}