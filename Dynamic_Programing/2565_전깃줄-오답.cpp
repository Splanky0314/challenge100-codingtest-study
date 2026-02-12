#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

/*
틀린 코드임. 

그리디 방식으로 구현 -> 현재 최선의 선택이 최종 최선의 결과 X
*/

int n;
vector<pair<int,int>> map;
int group[501]; // group[mapidx]
vector<int> pal[105];

bool is_crossed(int i, int j) {
    int a1 = map[i].first;
    int b1 = map[i].second;
    int a2 = map[j].first;
    int b2 = map[j].second;

    if(a1 < a2 && b1 < b2) return false;
    if(a1 > a2 && b1 > b2) return false;
    return true;
}

bool is_addable(int idx, int color) {
    for(int i=0; i<pal[color].size(); i++) {
        if(is_crossed(idx, pal[color][i])) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        map.push_back({a, b});
    }

    int color = 1;
    for(int i=0; i<n; i++) {
        if(group[i] == 0) {
            group[i] = color; 
            pal[color].push_back(i);
            for(int j=0; j<n; j++) {
                if(i==j) continue;
                if(is_addable(j, color)) {
                    group[j] = color; // 덮어쓰기
                    pal[color].push_back(j);
                }
            }
            color++;
        }
    }

    // for test
    // for(int i=0; i<n; i++) cout << group[i] << " ";
    // cout << endl;

    // for(int i=1; i<color; i++) {
    //     cout << "color "<< i << endl;
    //     for(int j=0; j<pal[i].size(); j++) {
    //         cout << map[pal[i][j]].first << "," << map[pal[i][j]].second << " ";
    //     }
    //     cout << endl;
    // } cout << endl;

    int maxval = pal[1].size();
    for(int i=2; i<color; i++) {
        if(pal[i].size() > maxval) {
            maxval = pal[i].size();
        }
    }

    cout << n - maxval;
}