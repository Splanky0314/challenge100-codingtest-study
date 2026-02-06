#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

vector<long> euclid(long a, long b) {
	vector<long> ret(2);
	if(b == 0) {
		ret[0] = 1;
		ret[1] = 0;
		return ret;
	}
	long q = a/b;

	vector<long> vec = euclid(b, a%b);
	ret[0] = vec[1];
	ret[1] = vec[0] - vec[1] * q;
	// cout << ret[0] << " " << ret[1] << endl;
	return ret;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	int x, y, k, gcdvar;

	cin >> a >> b >> c;
	if(c%(gcdvar = gcd(a, b)) == 0) {
		k = c/gcdvar;
		vector<long> ret = euclid(a, b);
		cout << ret[0]*k << " " << ret[1]*k;
	}
	else {
		cout << -1 << "\n";
	}

}
