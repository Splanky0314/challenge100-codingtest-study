#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 3/2 15:40

    int n;
    map<string, int> mp;
    string str;
    int maxval = 0;
    string maxstr;

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> str;
        mp[str]++;

        if(maxval < mp[str]) {
            maxval = mp[str];
            maxstr = str;
        }
        else if(maxval == mp[str]) {
            if(str < maxstr) {
                maxval = mp[str];
                maxstr = str;
            }
        }
    }

    cout << maxstr;
}   