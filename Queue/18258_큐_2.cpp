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

    int n, a;
    string cmd;
    queue<int> q;

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> cmd;
        if(cmd == "push") {
            cin >> a;
            q.push(a);
        }
        else if(cmd == "pop") {
            if(q.empty()) cout << -1 << "\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if(cmd == "size") {
            cout << q.size() << "\n";
        }
        else if(cmd == "empty") {
            cout << q.empty() << "\n";
        }
        else if(cmd == "front") {
            if(q.empty()) cout << -1 << "\n";
            else cout << q.front() << "\n";
        }
        else if(cmd == "back") {
            if(q.empty()) cout << -1 << "\n";
            else cout << q.back() << "\n";
        }
    }

}   