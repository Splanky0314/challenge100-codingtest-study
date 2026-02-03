#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

typedef struct Info {
	int w, h;
} Info;

bool islight(Info a, Info b) {
	if(a.w < b.w && a.h < b.h) return true;
	return false;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 2/3 15:2
	
	int n, w, h;
	vector<Info> infos;

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> w >> h; infos.push_back({w, h});
	}

	for(int i=0; i<n; i++) {
		int cnt = 1;
		for(int j=0; j<n; j++) {
			if(i==j) continue;
			if(islight(infos[i], infos[j])) {
				cnt++;
			}
		}
		cout << cnt << " ";
	}
}