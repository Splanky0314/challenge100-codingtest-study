#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

vector<int> child[51];
int parent[51];
int leafcnt = 0;
bool v[51];

void dfs(int x, int delnode) {
	v[x] = true;
	bool isleaf = true;
	if(x == delnode) return;
	for(int c: child[x]) {
		if(!v[c]) {
			if(c == delnode) continue;
			isleaf = false;
			dfs(c, delnode);
		}
	}
	if(isleaf) leafcnt++;
}
int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, iinput, root, delnode;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> iinput;
		if(iinput == -1) root = i;
		parent[i] = iinput;
		child[iinput].push_back(i);
	}
	cin >> delnode;

	dfs(root, delnode);

	cout << leafcnt;
}