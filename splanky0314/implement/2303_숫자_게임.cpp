#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007

using namespace std;
using ll = long long;

int n, arr[5];

int return_maxcomb() {
	int maxval = -1;
	for(int i=0; i<5; i++) {
		for(int j=i+1; j<5; j++) {
			for(int k=j+1; k<5; k++) {
				if(maxval < (arr[i] + arr[j] + arr[k]) % 10) {
					maxval = (arr[i] + arr[j] + arr[k]) % 10;
				}
			}
		}
	}
	return maxval;
}
int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int maxval = -1;
	int maxidx;
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<5; j++) {
			cin >> arr[j];
		}

		int result = return_maxcomb();
		// cout << i << "-" << result << endl; // for test
		if(maxval <= result) {
			maxval = result;
			maxidx = i;
		}
	}

	cout << maxidx + 1;
}