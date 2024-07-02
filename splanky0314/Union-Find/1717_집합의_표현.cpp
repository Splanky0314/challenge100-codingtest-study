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

bool checkSame(int a, int b) {
	a = find(a);
	b = find(b);

	if(a == b) return true;
	return false;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, a, b, com;
	
	cin >> n >> m;
	parent.resize(n+1);
	// init
	for(int i=0; i<=n; i++) {
		parent[i] = i;
	}

	for(int i=0; i<m; i++) {
		cin >> com >> a >> b;
		if(com == 0) { // union 연산
			union_func(a, b);
		}
		else { // find 연산
			if(checkSame(a, b)) {
				cout << "YES\n";
			}
			else cout << "NO\n";
		}
	}
}