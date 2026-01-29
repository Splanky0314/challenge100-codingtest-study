#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef struct Elem {
    int n, dist;
} Elem;

bool v[20001] = {};
vector<int> g[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;    
    
    int a, b;
    for(int i=0; i<edge.size(); i++) {
        a = edge[i][0]; b = edge[i][1];
        g[a].push_back(b); g[b].push_back(a);
    }
    
    // bfs
    int maxval = -1;
    queue<Elem> q;
    
    q.push({1, 0}); v[1] = true;
    while(!q.empty()) {
        Elem tmp = q.front(); q.pop();
        cout << tmp.n << " " << tmp.dist << endl;
        for(int y: g[tmp.n]) {
            if(!v[y]) {
                v[y] = true;
                q.push({y, tmp.dist+1});
            }
        }
        
        // is finished?
        bool isfinished = true;
        for(int i=1; i<=n; i++) {
            if(v[i] == false) isfinished = false;
        } 
        if(isfinished) {
            cout << "ISFIN\n";
            while(!q.empty()) {
                Elem tmp = q.front(); q.pop();
                cout << tmp.n << " " << tmp.dist << endl;
                if(maxval == -1 || maxval < tmp.dist) {
                    maxval = tmp.dist; answer = 1;
                }
                else if(maxval == tmp.dist) answer++;
            }
        }
    }
    
    return answer;
}