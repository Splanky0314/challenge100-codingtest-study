#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

string str, boom;
int len, boomlen;
vector<char> st;

bool check() {
    for(int k=0; k<boomlen; k++) {
        if(boom[k] != st[st.size() - boomlen + k]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 
    cin >> str >> boom;
    len = str.length(); boomlen = boom.length();

    for(int i=0; i<len; i++) {
        st.push_back(str[i]);
        if(check()) {
            for(int k=0; k<boomlen; k++) st.pop_back();
        }
    }

    // output
    if(st.size() == 0) cout << "FRULA";
    else 
        for(int i=0; i<st.size(); i++) 
            cout << st[i]; 
}   