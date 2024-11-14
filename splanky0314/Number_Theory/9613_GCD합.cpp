#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int gcd(int a, int b) {
	if(b == 0) return a;
	else return gcd(b, a%b);
} 

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// cout << gcd(21, 14);

	int T, n;
	int arr[101];
	ll sum;
	cin >> T;
	for(int t=0; t<T; t++) {
		sum = 0;
		cin >> n;
		for(int i=0; i<n; i++) {
			cin >> arr[i];
		}

		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				sum += gcd(arr[i], arr[j]);
			}
		}
		cout << sum << "\n";
	}
}