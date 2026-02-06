#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

string skeep = "skeep";
string s____ = "s____";

int n; string str;
vector<char> st;

bool compare() {
	int len = st.size()-1;
	for(int i=0; i<5; i++) {
		if(st[len-i] == skeep[4-i] || st[len-i] == s____[4-i]) {

		} else return false;
	}
	return true;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> str;
	int ans = 0;

	for(int i=0; i<n; i++) {
		st.push_back(str[i]);
		while (st.size() >= 5 && compare()) {
            for (int j = 0; j < 5; j++) st.pop_back();
            st.push_back('_'); 
            ans++;
        }
	}

	cout << ans;
}