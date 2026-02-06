#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s;
	char ans[50] = {};

	cin >> s;

	sort(s.begin(), s.end());

	int len = s.length();
	int fir = 0, sec = len-1;
	char spare = '*';
	for(int i=0; i<len; i++) {
		if(s[i] == '*') continue;
		// cout << s[i] << endl; // for test
		char tar = s[i];
		bool used = false;
		for(int j=0; j<len; j++) {
			if(i==j) continue;
			if(tar == s[j] && s[j] != '*') {
				ans[fir] = tar; ans[sec] = tar;
				fir++; sec--; s[j] = '*';
				used = true; break;
			}
		}
		if(!used) {
			if(spare != '*') {
				cout << "I'm Sorry Hansoo";
				return 0;
			}
			spare = s[i];
		}
		s[i] = '*';
	}

	if(len%2 == 1) {
		if(spare != -1) {
			ans[fir] = spare;
		}
	}

	
	for(int i=0; i<len; i++) {
		cout << ans[i];
	}
}