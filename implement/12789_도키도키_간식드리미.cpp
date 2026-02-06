#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, arr[1001];
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}

	int out = 1;
	stack<int> space;

	for(int i=0; i<n; i++) {
		int tar = arr[i];
		if(out == tar) out++;
		else space.push(tar);

		while(!space.empty() && space.top() == out) {
			space.pop(); out++;
		}
	}

	if(space.empty()) cout << "Nice";
	else cout << "Sad";
}