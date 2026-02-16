#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

enum Dir {Up, Ri, Dw,  Lf};
// R -> +1; L -> -1;

typedef struct Pos {
    int x, y;
} Pos;

int n, k, l;
int map[101][101];
/*
map == 5 : apple!
map == 1 : 뱀 몸
map == 0 : 빈 자리
*/

queue<Pos> q; // q.front()가 tail, q.back()이 head

Pos next_move(Dir d) {
    int x, y;
    switch (d) { // 기존 진행방향대로 이동
        case Up: // -1, 0
            x = q.back().x - 1; y = q.back().y; break;
        
        case Dw: // 1, 0
            x = q.back().x + 1; y = q.back().y; break;
        
        case Ri: // 0, 1
            x = q.back().x; y = q.back().y + 1; break;

        case Lf: // 0, -1
            x = q.back().x; y = q.back().y - 1; break;
    }

    return Pos{x, y};
}

bool is_valid(int x, int y) {
    if(0<=x && x<n && 0<=y && y<n) {
        if(map[x][y] == 5) { // apple!
            map[x][y] = 1;
            q.push({x, y});
            return true;
        }
        else if(map[x][y] == 0) { // ok to move!
            map[x][y] = 1;
            q.push({x, y});
            map[q.front().x][q.front().y] = 0;
            q.pop();
            return true;
        }
        else { // 자신에게 부딫
            return false;
        }
    }
    else { // 벽에 부딫
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b; char inp;

    cin >> n >> k;
    for(int i=0; i<k; i++) {
        cin >> a >> b;
        map[a-1][b-1] = 5;
    }
    
    Dir dir = Ri; 
    int time, settime;
    int x, y;

    time = 0;
    map[0][0] = 1;
    q.push({0, 0});

    cin >> l;
    for(int t=0; t<l; t++) {
        cin >> settime >> inp;

        for(int i=time+1; i<=settime; i++) {
            Pos tmp = next_move(dir);
            x = tmp.x; y = tmp.y;
            if(is_valid(x, y)) {

            }
            else {
                cout << i; return 0;
            }

            // // for test
            // cout << i << endl;
            // for(int i=0; i<n; i++) {
            //     for(int j=0; j<n; j++) {
            //         cout << map[i][j] << " ";
            //     } cout << endl;
            // } cout << endl;
        }

        if(inp == 'L') {
            dir = Dir((dir+4-1) % 4);
        }
        else if(inp =='D') {
            dir = Dir((dir+1)%4);
        }

        time = settime+1;

        Pos tmp = next_move(dir);
        if(is_valid(tmp.x, tmp.y)) {

        }
        else {
            cout << time; return 0;
        }

        // // for test
        // cout << "dirch " << time << endl;
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<n; j++) {
        //         cout << map[i][j] << " ";
        //     } cout << endl;
        // } cout << endl;
    }

    // 아직 안죽었다면
    for(int i=time+1; ; i++) {
        Pos tmp = next_move(dir);
        x = tmp.x; y = tmp.y;
        if(is_valid(x, y)) {

        }
        else {
            cout << i; return 0;
        }

        // // for test
        // cout << i << endl;
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<n; j++) {
        //         cout << map[i][j] << " ";
        //     } cout << endl;
        // } cout << endl;
    }
}   