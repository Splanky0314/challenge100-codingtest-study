#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int target, len = 64;
int sum = 64, cnt = 1;

void solve() {
    if(sum == target) return;

    while(sum > target) {
        int frac = len/2; 
        // cout << "len " << len << ", sum: " << sum << endl;
        if(sum - frac >= target) {
            sum -= frac;
            len = frac;
        }
        else if(sum - frac < target) {
            len = frac;
            cnt++;
        }
    }
    
    // if(sum < target) {
    //     cout << "CASE!" << endl; // for test
    // }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    

    cin >> target;

    solve();
    cout << cnt;
}