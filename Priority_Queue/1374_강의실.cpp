#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <functional>

using namespace std;
using ll = long long;

int n;
priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int,int>> arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, a, b;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> num >> a >> b;
        arr.push_back({a, b});
    }

    sort(arr.begin(), arr.end());

    pq.push(arr[0].second);
    int topt;
    for(int i=1; i<n; i++) {
        a = arr[i].first; b = arr[i].second;
        topt = pq.top();
        // cout << topt << " - " << a << "," << b << endl;
        if(topt <= a) {
            pq.pop(); pq.push(b);
            // cout << "POP " << topt << "END PUSH" << b << endl; // for test
        }
        else {
            pq.push(b);
            // cout << "PUSH " << b << endl; // for test
        }
    }

    cout << pq.size();
}