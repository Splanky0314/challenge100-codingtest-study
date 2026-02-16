#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n, m;
int parent[500001];

void init() {
    for(int i=1; i<=n; i++)
        parent[i] = i;
}

int findfunc(int a) {
    while(a != parent[a]) {
        a = parent[a];
    }
    return a;
}

bool unionfunc(int a, int b) {
    a = findfunc(a);
    b = findfunc(b);
    if(a != b) {
        parent[b] = a; return true;
    }
    return false; // 이미 동일한 그룹
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 2/17 03:15
    int a, b;

    cin >> n >> m;
    init();
    for(int i=1; i<=m; i++) {
        cin >> a >> b;
        
        if(!unionfunc(a, b)) {
            cout << i; return 0;
        }

        // // for test
        // for(int i=0; i<n; i++) {
        //     cout << parent[i] << " ";
        // } cout << endl;
    }

    cout << 0; // 종료되지 않음
}   