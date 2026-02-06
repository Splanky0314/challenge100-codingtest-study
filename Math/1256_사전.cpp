#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll n, m, k;
ll comb[201][201];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnta = 0;
	int cntz = 0;
	int pos = 0;
	ll quot;
	cin >> n >> m >> k;	

	// init combination
	for(int i=0; i<=n+m; i++) {
		comb[i][i] = 1;
		comb[i][0] = 1;
	}
	for(int i=1; i<=n+m; i++) {
		for(int j=1; j<i; j++) {
			comb[i][j] = comb[i-1][j-1] + comb[i-1][j];

			// overflow 처리
			if(comb[i][j] > 1000000000) { // k의 입력조건 활용
				comb[i][j] = 1000000001;
			}
		}
	}

	if(comb[n+m][n] < k) {
		cout << -1;
		return 0;
	}

	ll count;
	while(!(n == 0 && m == 0)) {
		count = comb[n+m-1][m];
		if(count < k) { // k >= count
			cout << "z";
			k -= count;
			m--;
		}
		else {
			cout << "a";
			n--;
		}
	}

	// // for test
	// for(int i=0; i<50; i++) {
	// 	for(int j=0; j<50; j++) {
	// 		cout << comb[i][j] << " ";
	// 	} cout << endl;
	// }
} 