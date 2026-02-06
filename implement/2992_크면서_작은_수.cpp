#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	string x;
	vector<int> arr;
	cin >> x;
	for(int i=0; i<x.length(); i++) {
		arr.push_back(int(x[i]) - '0');
	}

	int ii, jj;
	bool flag = 0;
	for(int i=x.length()-1; i>=0; i--) {
		for(int j=i-1; j>=0; j--) {
			if(arr[j] < arr[i]) {
				// cout << "SWAP " << i << " " << j << endl;
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				ii = i; jj = j; flag = true;
				break;
			}
		}
		if(flag) break;
	} 

	if(!flag) {
		cout << "0"; return 0;
	}
	sort(arr.begin() + jj + 1, arr.end());

	for(int i=0; i<x.length(); i++) cout << arr[i];
}