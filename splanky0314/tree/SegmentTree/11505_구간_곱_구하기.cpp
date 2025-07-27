#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n, m, k, K = 1;;
vector<ll> segtree;

void init_segtree() {
	for(int KK = K/2; KK > 0; KK/=2) {
		for(int i=KK; i<KK*2; i++) {
			// 비어있는 노드라면,
			if(segtree[i*2] == -1 && segtree[i*2 + 1] == -1) segtree[i] = -1;
			else if(segtree[i*2 + 1] == -1) segtree[i] = segtree[i*2];
			else if(segtree[i*2] == -1) segtree[i] = segtree[i*2+1]; // 아마 존재 X 경우일 듯
			else segtree[i] = segtree[i*2] * segtree[i*2 + 1] % 1000000007;;
		}
	}
}

void update_segtree(int idx, ll val) {
	ll prevval = segtree[idx];
	segtree[idx] = val;
	idx /= 2;
	while(idx > 0) {
		if(prevval == -1) segtree[idx] = (segtree[idx] * val) % 1000000007;
		else segtree[idx] = (segtree[idx*2] * segtree[idx*2 + 1]) % 1000000007;
		// else segtree[idx] = segtree[idx] / prevval * val % 1000000007;
		// 나누기는 % 분배법칙 성립하지 않는다?!
		idx /= 2; 
	}
}

ll search(int l, int r) {
	ll mulsum = 1;
	while(l <= r) {
		if(l%2 == 1) {
			mulsum = (mulsum * segtree[l]) % 1000000007;
			l++;
		}
		if(r%2 == 0) {
			mulsum = (mulsum * segtree[r]) % 1000000007;
			r--;
		}
		l /= 2; r /= 2;
	}
	return mulsum;
}

void print_segtree() {
	for(int i=1; i<K+n; i++) {
		cout << segtree[i] << " | ";
	} cout << endl << endl;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int a, b, c;
	cin >> n >> m >> k;

	while(K <= n) K *= 2;
	segtree.resize(K*2 + 1);

	// -1로 segtree 초기화
	for(int i=0; i<K*2+1; i++) segtree[i] = -1;

	for(int i=0; i<n; i++) {
		cin >> segtree[K + i];
	}
	init_segtree();
	// print_segtree(); // for test;

	for(int i=0; i<m + k; i++) {
		cin >> a >> b >> c;
		if(a == 1) { // b번째 수를 c로 바꾸기
			update_segtree(K+b-1, c);
			// print_segtree(); // for test
		}
		else if(a == 2) { // b ~ c 구간 곱 출력
			cout << search(K + b - 1, K + c - 1) % 1000000007 << "\n";
		}
	}
}