#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

vector<int> segtree;
int n, m;
int K = 1;	

void init_segtree() { // min segment tree
	for(int KK = K/2; KK > 0; KK /= 2) {
		for(int i=KK; i<KK*2; i++) {
			if(segtree[i*2 + 1] == 0) segtree[i] = segtree[i*2];
			else segtree[i] = segtree[i*2] < segtree[i*2+1] ? segtree[i*2] : segtree[i*2 + 1];
		}
	}
}

int search(int l, int r) {
	int minval = -1;
	while(l <= r) {
		// cout << "LR: "<< l << ", " << r << endl; // for test
		if(l%2 == 1) {
			if(minval == -1 || minval > segtree[l]) 
				minval = segtree[l];
			l++;
		}
		if(r%2 == 0) {
			if(minval == -1 || minval > segtree[r])
				minval = segtree[r];
			r--;
		}
		l /= 2;
		r /= 2;
	}
	return minval;
}

void printsegtree() {
	for(int i=1; i<=K*2; i++) {
		cout << segtree[i] << " | ";
	} cout << endl << endl;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> n >> m;

	// K 찾기
	while(K <= n) {
		K *= 2;
	}
	segtree.resize(K*2 + 1);

	for(int i=0; i<n; i++) {
		cin >> segtree[K + i];
	}
	init_segtree();

	// printsegtree(); // for test

	for(int i=0; i<m; i++) {
		cin >> a >> b;
		cout << search(a + K -1, b + K -1) << "\n";
	}
}