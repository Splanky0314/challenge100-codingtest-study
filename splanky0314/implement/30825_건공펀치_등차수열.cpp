#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, k, tmp;
	ll cur;
	ll sum = 0;
	cin >> n >> k;

	cin >> tmp;
	cur = tmp;
	for(int i=1; i<n; i++) {
		cin >> tmp;
		cur += k;
		sum += cur-tmp;
		if(cur-tmp < 0) {
			sum += (i+1)*(tmp-cur);
			cur = tmp;
		}
	}

	cout << sum;
}