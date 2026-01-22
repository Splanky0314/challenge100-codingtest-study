#include<vector>
#include <queue>
using namespace std;

typedef struct elem {
    int x, y;
    int dist;
} elem;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int v[101][101];

int solution(vector<vector<int> > maps)
{
    // 1/22 15:09    
    queue<elem> q;
    q.push({0, 0, 1});
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int dist = q.front().dist;
        q.pop();
        if(v[x][y] == 0 || v[x][y] > dist) {
            v[x][y] = dist;
        } else continue;
        
        if(x == maps.size()-1 && y == maps[0].size()-1) {
            return dist;
        }
        
        for(int k=0; k<4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if(0<=nx && nx < maps.size() && 0<= ny && ny <maps[0].size()) {
                if(!v[nx][ny] && maps[nx][ny])
                    q.push({nx, ny, dist+1});
            }
        }
    }
    
    return -1;
}