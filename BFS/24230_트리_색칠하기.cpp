#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;
using ll = long long;

int n;
int color[200001];
vector<int> g[200001];
bool v[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 3/2 22:25
    int a, b;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> color[i];
    }
    for(int i=0; i<n-1; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    queue<int> q;
    int cnt = 0;
    int x, xcol;

    q.push(1);
    if(color[1] != 0) cnt++;
    while(!q.empty()) {
        x = q.front(); 
        xcol = color[x];
        q.pop();
        v[x] = true;

        for(int y: g[x]) {
            if(!v[y]) {
                int ycol = color[y];
                if(xcol != ycol) {
                    cnt++;
                }
                q.push(y);
            } 
        }
    }

    cout << cnt;
}