#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, len;
	vector<bool> ans;

	cin >> n;
	while(n > 0) {
		ans.push_back(n%2);
		n/=2;
	}

	len = ans.size();
	for(int i=0; i<len; i++) {
		if(ans[i] == 1) {
			cout << i << " ";
		}
	} 
}