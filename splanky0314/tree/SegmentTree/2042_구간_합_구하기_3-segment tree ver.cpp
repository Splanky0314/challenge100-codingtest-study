#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n, m, k, K = 1;
vector<ll> segtree;

void inittree() {
	for(int KK = K/2; KK > 0; KK /= 2) {
		for(int i = KK; i < KK*2; i++) {
			segtree[i] = segtree[i*2] + segtree[i*2 + 1];
		}
	}
}

void update(int x, ll val) {
	ll diff = val - segtree[x];
	while(x > 0) {
		segtree[x] += diff;
		x /= 2;
	}
}

ll search(int l, int r) {
	if(l == r) return segtree[l];

	ll sum = 0;
	while(l <= r) {
		if(l%2 == 1) {
			sum += segtree[l];
			l++;
		}
		if(r%2 == 0) {
			sum += segtree[r];
			r--;
		}
		l /= 2; r /= 2;
	}
	return sum;
}

// for test
void printresult() {
	// for test
	for(int i=0; i<K*2+1; i++) {
		cout << segtree[i] << "| ";
	} cout << endl << endl;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	ll a, b, c;
	
	cin >> n >> m >> k;

	// (K = 2^i) >= n에서 K 계산
	while(K < n) {
		K *= 2;
	}

	segtree.resize(K*2+1);
	for(int i=0; i<n; i++) {
		cin >> segtree[K + i];
	}
	inittree();
	// printresult(); // for test
 
	for(int T=0; T<m + k; T++) {
		cin >> a >> b >> c;
		if(a == 1) { // b번째 수를 c로 바꾸기
			update(K + b - 1, c); // 부모부터 refresh 시작
			// printresult(); // for test;
		}
		else if(a == 2) { // b ~ c번째 수까지의 합을 출력
			cout << search(K + b - 1, K + c - 1) << "\n";
		}
	}
	
}