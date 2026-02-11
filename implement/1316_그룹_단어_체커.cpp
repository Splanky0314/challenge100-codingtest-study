#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // s#1000.. *g3..s3 !@$me
    int n, ans = 0;
    string str;

    cin >> n;
    for(int t=0; t<n; t++) {
        vector<bool> v(26);
        bool succ = true;

        cin >> str;
        v[str[0] - 'a'] = true;
        for(int i=1; i<str.length(); i++) {
            if(str[i-1] != str[i]) {
                if(v[str[i] - 'a']) { // 연속 아닌 경우
                    succ = false;
                    break;
                }
                else {
                    v[str[i] - 'a'] = true;
                }
            }
        }

        if(succ) ans++;
    }

    cout << ans;
}