#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
using ll = long long;

int l, n;
vector<int> arr;
vector<pair<unsigned long long,int>> prior; // {좋은구간개수, 해당 수}
// int dp[10000];
unordered_map<int,unsigned long long> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> l; arr.resize(l+1);
    arr[0] = 0;
    for(int i=1; i<=l; i++) {
        cin >> arr[i];
        prior.push_back({1, arr[i]});
    }
    cin >> n;

    sort(arr.begin(), arr.end());

    int idx = 1;
    int cumul = 0;
    int num;
    dp[1] = arr[1] - 1;
    for(int i=1; ; i++) {
        if(n < cumul && i + n < arr[idx]) {
            cumul += (arr[idx]-n) - i;
            i = arr[idx] - n;
        }

        if(i == arr[idx]) { // i가 S에 소속된 수인 경우
            if(idx+1 > l) {
                // TODO
                num = i+1; break;
            }
            dp[i+1] = arr[idx+1] - arr[idx] - 1;
            cumul = 0;
            idx++; 
            continue;
        }

        // dp[i] = (dp[i-1] - cumul) / max(cumul, 1) * (cumul+1);
        dp[i] = (dp[i-cumul] - cumul) * (cumul+1);
        prior.push_back({dp[i], i});
        cumul++;
    }

    // output
    // cout << "NUM";
    // cout << num << endl << endl;
    sort(prior.begin(), prior.end());

    for(int i=0; i<n; i++) {
        if(prior.size() <= i) {
            cout << (num++) << " ";
        }
        else {
            cout << prior[i].second << " ";
        }
    }

    // for test
    // cout << "TEST\n";
    // // for(int i=1; i<=n; i++) {
    // //     cout << dp[i] << " ";
    // // }
    // cout << dp[1] << endl;
    // cout << dp[500000002] << endl;
    // cout << dp[999999999] << endl;
}   