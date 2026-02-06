#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

int n, m;
vector<int> arr; int x;

bool binary_search(int target) {
	int l = 0, r = n-1, mid = (l+r)/2;
	while(l <= r) {
		mid = (l+r)/2;
		if(arr[mid] == target) return true;
		else if(arr[mid] < target) l = mid+1;
		else r = mid-1;
	}
	return false;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> x; arr.push_back(x);
	}
	sort(arr.begin(), arr.end());
	
	int inp; 
	cin >> m;
	for(int i=0; i<m; i++) {
		cin >> inp; 
		cout << binary_search(inp) << " ";
	}
}