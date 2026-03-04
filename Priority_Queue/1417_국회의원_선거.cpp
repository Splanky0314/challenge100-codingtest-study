#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 3/4 Wed 15:16
    int n;
    priority_queue<int> arr;
    int maxval = 0, maxidx = -1;
    int initial_val;

    int tmp, dasom;
    cin >> n;
    cin >> dasom; initial_val = dasom;
    for(int i=1; i<n; i++) { 
        cin >> tmp;
        if(initial_val <= tmp)
            arr.push(tmp);
    }

    while(!arr.empty()) {
        tmp = arr.top(); arr.pop();
        if(dasom > tmp) break;

        if(dasom <= tmp) {
            dasom++;
            arr.push(tmp-1);
        }
    }
    
    cout << dasom - initial_val;
}