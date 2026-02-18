#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 2/17 14:30

    int n;
    cin >> n;

    while(true) {
        // 상근 먼저
        if(n == 1 || n == 3) {
            cout << "CY"; return 0;
        }
        else if(n<3) {
            n--;
        }
        else { // 3 초과
            n-=3;
        }

        // 창영 다음
        if(n == 1 || n == 3) {
            cout << "SK"; return 0;
        }
        else if(n<3) {
            n--;
        }
        else { // 3 초과
            n-=3;
        }
    }
}   