#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;
    // if(n < 3) cout << 0;
    if(n < 6) cout << n;
    else if(n == 6) cout << 7;
    else {
        ll result = 7;
        int frac = 2;
        for(int i=6; i<n; i++) {
            if((i+1)%6 == 0) frac++;

            if(i%6 == 0) result += (frac-1);
            else result += frac;
        }

        cout << result;
    }
}