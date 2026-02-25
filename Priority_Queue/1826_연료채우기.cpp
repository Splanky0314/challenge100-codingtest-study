#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;
using ll = long long;

typedef struct Elem {
    int dist, fuel;

    bool operator<(const Elem& e) const {
        return dist < e.dist;
    }
} Elem;

int n, dest, capa;
vector<Elem> map;
priority_queue<int> pq; // fuel만

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 
    int a, b; int ans = 0;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        map.push_back({a, b});
    } cin >> dest >> capa;

    sort(map.begin(), map.end());

    int pos = 0;
    for(int i=0; i<n; i++) {
        // cout << i << ">" << endl;

        while(map[i].dist - pos > capa) {
            if(pq.empty()) {
                cout << -1; return 0;
            }
            
            int tmp = pq.top(); pq.pop();
            
            capa += tmp;
            // cout << "pop" << tmp << " " << capa << endl;
            ans++;
        }

        // cout << "pushed" << map[i].fuel << endl;

        pq.push(map[i].fuel);
        capa = capa - (map[i].dist - pos);
        pos = map[i].dist;

        // cout << capa << endl;
    }

    while(dest - pos > capa) {
        if(pq.empty()) {
            cout << -1; return 0;
        }
        
        int tmp = pq.top(); pq.pop();
        
        capa += tmp;
        // cout << "pop" << tmp << " " << capa << endl;
        ans++;
    }

    cout << ans;
}   