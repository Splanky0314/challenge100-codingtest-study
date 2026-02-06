#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string tmpa, tmpb;
	vector<vector<int>> dp;
	cin >> tmpa >> tmpb;
	dp.resize(tmpa.size()+1, vector<int>(tmpb.size()+1));

	for(int i=0; i<tmpa.size(); i++) {
		for(int j=0; j<tmpb.size(); j++) {
			if(tmpa[i] == tmpb[j]) {
				dp[i+1][j+1] = dp[i][j] + 1;
			}
			else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
		}
	}
	
	// for test
	// for(int i=0; i<tmpa.size(); i++) {
	// 	for(int j=0; j<tmpb.size(); j++) {
	// 		cout << dp[i+1][j+1] << " ";
	// 	} cout << endl;
	// } cout << endl;

	int i=tmpa.size(), j=tmpb.size();
	vector<char> ans;
	while(i>0 && j>0) {
		if(tmpa[i-1] == tmpb[j-1]) {
			ans.push_back(tmpa[i-1]);
			i--; j--;
		}
		else {
			if(dp[i-1][j] < dp[i][j-1]) {
				j--;
			}
			else i--;
		}
	}

	cout << ans.size() << "\n";
	for(int i=ans.size()-1; i>=0; i--) {
		cout << ans[i];
	}
}