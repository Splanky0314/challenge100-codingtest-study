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
    int n, x, y; vector<int> a;
    int tmp;

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> tmp; a.push_back(tmp);
    } cin >> x >> y;

    sort(a.begin(), a.end());

    int idx = (n * x / double(100));
    cout << idx << " ";
    idx = 0;
    while(a[idx] < y) {
        idx++;
    }
    cout << max(n - idx, 0);
}