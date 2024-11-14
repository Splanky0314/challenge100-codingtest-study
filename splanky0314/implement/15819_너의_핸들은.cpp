#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long;

string arr[101];

void swap(int a, int b) {
	if(arr[a] > arr[b]) {
		string tmp = arr[a];
		arr[a] = arr[b];
		arr[b] = tmp;
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, I;
	
	cin >> n >> I;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}

	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			swap(i, j);
		}
	}

	//fortest
	// for(int i=0; i<n; i++) {
	// 	cout << arr[i] << endl;
	// }

	cout << arr[I-1];
}