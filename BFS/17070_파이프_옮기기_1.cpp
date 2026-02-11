#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

enum Dir {Right, Down, Cross, None};

int n;
int map[17][17];

typedef struct Elem {
    int x1, y1; // left up 
    int x2, y2; // right down
    Dir dir;

    bool isexist() {
        if(dir == None) return false;
        return true;
    }

    bool isvalid() {
        if(dir == Cross) {
            for(int i=x1; i<=x2; i++) {
                for(int j=y1; j<=y2; j++) {
                    if(0<=i&&i<n&&0<=j&&j<n) {
                        if(map[i][j] == 1) return false;
                    }
                    else return false;                    
                }
            }            
            return true;
        }

        if(0<=x1&&x1<n&&0<=y1&&y1<n && map[x1][y1] == 0) {
            if(0<=x2&&x2<n&&0<=y2&&y2<n && map[x2][y2] == 0) {
                return true;
            }
        }
        return false;
    }

    Elem move_right() {
        if(dir == Right) {
            // y1++; y2++;
            Elem result = {x1, y1+1, x2, y2+1, Right};
            if(result.isvalid()) return result;
        }
        else if(dir == Cross) {
            // x1 = x2; y1 = y2;
            // x2 = x1; y2 = y1+1;
            Elem result = {x2, y2, x2, y2+1, Right};
            if(result.isvalid()) return result;
        }

        return {-1, -1, -1, -1, None};
    }
    Elem move_down() {
        if(dir == Down) {
            // x1++; x2++;
            Elem result = {x1+1, y1, x2+1, y2, Down};
            if(result.isvalid()) return result;
        }
        else if(dir == Cross) {
            // x1 = x2; y1 = y2;
            // x2 = x1+1; y2 = y1;
            Elem result = {x2, y2, x2+1, y2, Down};
            if(result.isvalid()) return result;
        }

        return {-1, -1, -1, -1, None};
    }
    Elem move_right_down() {
        if(dir == Right) {
            // x1 = x2; y1 = y2;
            // x2 = x1+1; y2 = y1+1;
            Elem result = {x2, y2, x2+1, y2+1, Cross};
            if(result.isvalid()) return result;
        }
        else if(dir == Down) {
            // x1 = x2; y1 = y2;
            // x1 = x2+1; y2 = y1;
            Elem result = {x2, y2, x2+1, y2+1, Cross};
            if(result.isvalid()) return result;
        }
        else if(dir == Cross) {
            // x1++; y1++; x2++; y2++;
            Elem result = {x1+1, y1+1, x2+1, y2+1, Cross};
            if(result.isvalid()) return result;
        }

        return {-1, -1, -1, -1, None};
    }

    // for test
    void print() {
        cout << "Info: " << dir << " | " << x1 << "," << y1 << " / " << x2 << "," << y2 << endl;
    }
} Elem;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 2/11 17:40
    queue<Elem> q; int ans = 0;

    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> map[i][j];

    q.push({0, 0, 0, 1, Right});
    while(!q.empty()) {
        Elem elem = q.front(); q.pop();
        if(elem.x2 == n-1 && elem.y2 == n-1) {
            ans++; continue;
        }
        
        // for test
        // elem.print();

        Elem tmp;
        switch (elem.dir) {
        case Right: // -> right, right down
            tmp = elem.move_right();
            if(tmp.isexist()) {
                q.push(tmp);
            }
            tmp = elem.move_right_down();
            if(tmp.isexist()) {
                q.push(tmp);
            }
            break;
        
        case Down: // -> down, right down
            tmp = elem.move_down();
            if(tmp.isexist()) {
                q.push(tmp);
            }
            tmp = elem.move_right_down();
            if(tmp.isexist()) {
                q.push(tmp);
            }
            break;
        
        case Cross: // -> right, down, rightdown
            tmp = elem.move_right();
            if(tmp.isexist()) q.push(tmp);
            tmp = elem.move_down();
            if(tmp.isexist()) q.push(tmp);
            tmp = elem.move_right_down();
            if(tmp.isexist()) q.push(tmp);
            break;
        }
    }

    cout << ans;
}