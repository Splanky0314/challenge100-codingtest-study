#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000

using namespace std;
using ll = long long;

int n, ans = 0;
int memo[100000];

int solve(int x, int cnt) {
    if(x == 0) return cnt;
    if(memo[x]) return memo[x];

    int res1 = MAX, res2 = MAX;
    if(x >= 5) {
        res1 = solve(x-5, cnt+1);
    }
    if(x >= 2) {
        res2 = solve(x-2, cnt+1);
    }

    // cout << x << " " << cnt << "-" << res1 << " " << res2 << endl; // for test

    return memo[x] = min(res1, res2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // memo[1] = -1;

    cin >> n;

    int tmp = solve(n, 0);
    if(tmp == MAX) cout << -1;
    else cout << tmp;

    // // for test
    // cout << endl << endl;
    // for(int i=0; i<=n; i++) {
    //     cout << memo[i] << " ";
    // } cout << endl;
}   