#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int pcard[10000001];
int mcard[10000001];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, tmp;	

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> tmp;
		if(tmp >= 0) {
			pcard[tmp]++;
		}
		else mcard[-tmp]++;
	}

	cin >> m;
	for(int i=0; i<m; i++) {
		cin >> tmp;
		if(tmp >= 0) {
			cout << pcard[tmp] << " ";
		}
		else cout << mcard[-tmp] << " ";
	}
}