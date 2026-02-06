#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n, m, k;
ll tree[4000004];
ll arr[1000001];

ll init(int start, int end, int idx) {
	if(start == end) {
		return tree[idx] = arr[start];
	}
	int mid = (start + end) / 2;
	return tree[idx] = init(start, mid, idx*2) + init(mid+1, end, idx*2 + 1);
}

ll sumfunc(int start, int end, int idx, int left, int right) {
	if(end < left || right < start) return 0;
	if(left <= start && end <= right) {
		return tree[idx];
	}
	int mid = (start + end) / 2;
	return sumfunc(start, mid, idx*2, left, right) + sumfunc(mid+1, end, idx*2+1, left, right);
}

void updatefunc(int start, int end, int idx, int targetidx, ll diff) {
	if(targetidx < start || end < targetidx) return;
	tree[idx] += diff;
	if(start == end) return;
	int mid = (start + end) / 2;
	updatefunc(start, mid, idx*2, targetidx, diff);
	updatefunc(mid+1, end, idx*2+1, targetidx, diff);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll a, b, c;
	cin >> n >> m >> k;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	init(0, n-1, 1);

	

	// cout << "MEMO" << endl;
	// for(int i=0; i<=10; i++) {
	// 	cout << memo[i] << endl;
	// }

	for(int i=0; i<m+k; i++) {
		// cout << "!" << i << endl; //
		cin >> a >> b >> c;
		if(a == 1) { // 수 바꾸기
			b--;
			ll value = c - arr[b];
			arr[b] = c;
			updatefunc(0, n-1, 1, b, value);

			// for test
			// for(int i=0; i<=10; i++) {
			// 	cout << i << ": " << tree[i] << "|";
			// } cout << endl;
		}
		else { // 구간합 출력
			b--; c--;
			cout << sumfunc(0, n-1, 1, b, c) << "\n";
		}
	}
}