#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<char> st;
    string s; int ans = 0;
    cin >> s;

    for(int i=0; i<s.length(); i++) {
        if(s[i] == '(') {
            st.push('(');
        }
        else if(s[i] == ')') {
            if(st.empty()) {
                ans++;
            }
            else {
                st.pop();
            }
        }
    }

    while(!st.empty()) {
        ans++; st.pop();
    }

    cout << ans;
}