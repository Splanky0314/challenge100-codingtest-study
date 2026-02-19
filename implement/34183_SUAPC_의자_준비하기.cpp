#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int cnt = n * 3;
    if(m < cnt) { // 의자 부족
        cout << (b + (cnt - m)*a);
    }
    else {
        cout << 0;
    }
}   