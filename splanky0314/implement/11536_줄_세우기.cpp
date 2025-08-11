#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<string> arr;
	string tmp, bef;

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}

	int isincre = 0;
	int isdecre = 0;
	bef = arr[0];
	for(int i=1; i<n; i++) {
		if(bef < arr[i]) { // incre
			if(isdecre) {
				cout << "NEITHER";
				return 0;
			}
			isincre = 1;
		}
		else if(bef > arr[i]) {
			if(isincre) {
				cout << "NEITHER";
				return 0;
			}
			isdecre = 1;
		}
		bef = arr[i];
	}
	if(isincre) cout << "INCREASING";
	else if(isdecre) cout << "DECREASING";
	else cout << "NEITHER";
}