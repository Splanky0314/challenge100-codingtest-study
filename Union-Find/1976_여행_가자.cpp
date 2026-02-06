#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

vector<int> parent;

int find(int a) {
	if(parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

void union_func(int a, int b) {
	a = find(a);
	b = find(b);

	if(a != b) parent[b] = a;
}

bool checkSame(int &a, int &b) {
	a = find(a);
	b = find(b);
	
	if(a == b) return true;
	return false;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	bool val;

	cin >> n >> m;
	// init
	parent.resize(n+1);
	for(int i=0; i<=n; i++) {
		parent[i] = i;
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin >> val;
			if(val) {
				union_func(i, j);	
			}
		}
	}

	int prev, cur;
	cin >> cur;
	for(int i=1; i<m; i++) {
		prev = cur;
		cin >> cur;

		if(!checkSame(prev, cur)) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}