#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

unsigned long long a, b;

unsigned long long calc(unsigned long long x) {
    unsigned long long result = 0;
    result += 1 * ((x+1)/2);
    result += 2 * (x/2);
    
    for(unsigned long long two=2; two<=x; two*=2) {
        result += two * (x / (two*2));
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 3/4 Wed 14:37
    unsigned long long sa = 0, sb = 0;
    cin >> a >> b;
    
    sa = calc(a-1);
    sb = calc(b);

    cout << (sb - sa);
    // cout << sa << " " << sb << endl;
}