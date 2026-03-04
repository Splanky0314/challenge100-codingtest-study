#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using ll = long long;

int n, m, l;
vector<int> arr;
vector<int> dists;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tmp;
    cin >> n >> m >> l;
    arr.push_back(0);
    for(int i=0; i<n; i++) {
        cin >> tmp;
        arr.push_back(tmp);
    }
    arr.push_back(l);

    sort(arr.begin(), arr.end());
    for(int i=0; i<arr.size()-1; i++) {
        dists.push_back(arr[i+1] - arr[i]);
    }
    sort(dists.begin(), dists.end(), greater<int>());


    for(int target=1; target < l; target++) {
        // cout << "TARGET "<< target << endl;

        int cnt = 0;
        for(int i=0; i<dists.size(); i++) {
            int dist = dists[i];
            if(dist <= target) continue; // 이미 조건 만족

            for(int div=2; cnt <= m; div++) {
                if((dist + div - 1) / div <= target) {
                    cnt += div - 1; break;
                }
            }
            if(cnt > m) break;
        }

        // cout << "CNT " << cnt << endl;
        if(cnt <= m) {
            cout << target;
            return 0;
        }
    }

}