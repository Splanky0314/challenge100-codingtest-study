#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int dw[500001];
int up[500001];
int dpdw[500001];
int dpup[500001];
int cave[500001];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 2/2 1:53
	int n, h, tmp;
	
	cin >> n >> h;
	for(int i=0; i<n; i++) {
		cin >> tmp; 
		if(i%2 == 0) dw[tmp] += 1;
		else up[tmp] += 1;
	} 


	int minval = -1, cnt = 0;
	dpdw[h] = dw[h];
	dpup[h] = up[h];
	for(int i=h-1; i>0; i--) {
		dpdw[i] = dw[i] + dpdw[i+1];
		dpup[i] = up[i] + dpup[i+1];
	}

	// for(int i=1; i<=h; i++) cout << dpdw[i] << " ";
	// cout << endl;
	// for(int i=1; i<=h; i++) cout << dpup[i] << " ";
	// cout << endl;

	for(int i=1; i<=h; i++) {
		cave[i] = dpdw[i] + dpup[h+1-i];
		// cout << cave[i] << " ";
		if(minval == -1 || cave[i] < minval) {
			minval = cave[i]; cnt = 1;
		}
		else if(minval == cave[i]) cnt++;
	} 
	// cout << endl;

	cout << minval << " " << cnt;
}