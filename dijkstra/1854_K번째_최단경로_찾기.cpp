#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;
using ll = long long;

int g[1001][1001]; // adj list로
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
vector<priority_queue<int>> qlist;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	int a, b, c;
	cin >> n >> m >> k;
	qlist.resize(n+1);

	for(int i=0; i<m; i++) {
		cin >> a >> b >> c;
		g[a][b] = c;
	}

	int target = 1, weight, w;
	qlist[target].push(0);
	q.push({0, target});
	while(!q.empty()) {
		// cout << "target: "<< target << endl; //
		target = q.top().second;
		weight = q.top().first;
		q.pop();
		for(int i=1; i<=n; i++) {
			if(w = g[target][i]) {
				// cout << target << "-" << i << "-" << w << endl;
				if(qlist[i].size() < k) {
					qlist[i].push(weight + w);
					q.push({weight+w, i});
				}
				else if(qlist[i].top() > weight + w) {
					qlist[i].pop();
					qlist[i].push(w + weight);
					q.push({weight+w, i});
				}
			}
		}
	}

	for(int i=1; i<=n; i++) {
		if(qlist[i].size() < k) {
			cout << "-1\n";
		}
		else {
			if(qlist[i].size() == k) {
				cout << qlist[i].top() << "\n";
			}
			else cout << "-1\n";
		}
	}
}