#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;

typedef struct Cir {
    int x, y, r;
} Cir;

bool is_in(int x, int y, Cir cir) {
    int sqared_dist = (x - cir.x)*(x - cir.x) + (y - cir.y)*(y - cir.y);
    if(sqared_dist < cir.r * cir.r) {
        return true;
    } return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    pair<int,int> str, dest;
    int n, x, y, r, ans;
    Cir tmp;

    cin >> T;
    for(int t=0; t<T; t++) {
        ans = 0;

        cin >> str.first >> str.second;
        cin >> dest.first >> dest.second;

        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> x >> y >> r;
            tmp = {x, y, r};

            bool res1 = is_in(str.first, str.second, tmp);
            bool res2 = is_in(dest.first, dest.second, tmp);

            if(res1 && res2) { // 둘 다 원의 내부에 존재

            } 
            else if(res1 || res2) { // 둘 중 하나만 원의 내부에 존재
                ans++;
            }
            else { // 둘 다 원 내부에 존재 X

            }
        }

        // cout << "ANS: ";
        cout << ans << "\n";
    }  
}