#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;

int n, d;
vector<int> nodes;

vector<pair<int,int>> g[10001];
int minval = 10000000;
void dfs(int x, int dist) {
    if(x == d) {
        minval = min(minval, dist);
        return;
    }
    else if(x > d) return; // 고속도로를 지나는 경우 제외

    for(pair<int,int> pii: g[x]) {
        int y = pii.first;
        int w = pii.second;
        dfs(y, dist + w);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    cin >> n >> d;
    for(int i=0; i<n; i++) {
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        nodes.push_back(a); 
        nodes.push_back(b);
    }
    nodes.push_back(0);
    nodes.push_back(d);

    sort(nodes.begin(), nodes.end());

    for(int i=0; i<nodes.size()-1; i++) {
        a = nodes[i]; b = nodes[i+1];
        if(a != b) {
            g[a].push_back({b, (b - a)});
        }
    }

    dfs(0, 0);
    cout << minval;
}