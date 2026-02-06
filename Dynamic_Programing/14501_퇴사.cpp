#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;

int n;
vector<pair<int,int>> info;
ll ans;
ll dp[16];

// ll func(ll x) {
// 	if(dp[x]) return dp[x];
// 	if(x == n) return dp[x] = 
// 	if(x+1 <= n && x+info[x].first <= n)
// 		return dp[x] = max(func(x+1), func(x+info[x].first));
// 	else if(x + 1 <= n) 
// 		return func(x+1);
// 	else if(x + info[x].first <= n)
// 		return func(x + info[x].first);
// }

ll func(ll x) {
	if(x == n) return 0;
	if(x + 1 <= n && x + info[x].first <= n)
		return max(func(x+1), func(x + info[x].first) + info[x].second);
	else if(x + 1 <= n) 
		return func(x+1);
	else if(x + info[x].first <= n)
		return func(x + info[x].first) + info[x].second;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, p;
	cin >> n;
	info.push_back({0,0}); // 1일부터 시작하게 dummy info임
	for(int i=0; i<n; i++) {
		cin >> t >> p;
		info.push_back({t, p});
	}
	n++;
	cout << func(1);
}