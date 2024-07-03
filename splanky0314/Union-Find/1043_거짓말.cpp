#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int parent[51];
vector<int> party[51];
vector<int> know;

int find(int a) {
	if(parent[a] == a) return a;
	return parent[a] = find(parent[a]); 
}

void union_func(int a, int b) {
	a = find(a);
	b = find(b);

	if(a != b) parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int cnt, tmp, tmp2;
	cin >> n >> m;
	// init
	for(int i=0; i<=n; i++) {
		parent[i] = i;
	}

	cin >> cnt;
	for(int i=0; i<cnt; i++) {
		cin >> tmp;
		know.push_back(tmp);
	}

	for(int i=0; i<m; i++) {
		cin >> cnt;
		cin >> tmp;
		party[i].push_back(tmp);
		for(int j=1; j<cnt; j++) {
			cin >> tmp2;
			party[i].push_back(tmp2);
			union_func(tmp, tmp2);
		}
	}

	int count = 0;

	for(int i=0; i<m; i++) {
		bool flag = 1;
		int cur = party[i][0];
		for(int j=0; j<know.size(); j++) {
			if(find(cur) == find(know[j])) {
				flag = 0;
				break;
			}
		}
		if(flag) {
			count++;
		}
	}

	cout << count;
}