#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
using ll = long long;

int n, m;
map<string, string> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 3/1 Sun 11:55
    string a, b;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        mp[a] = b;
    }

    for(int i=0; i<m; i++) {
        cin >> a;
        cout << mp[a] << "\n";
    }
}   