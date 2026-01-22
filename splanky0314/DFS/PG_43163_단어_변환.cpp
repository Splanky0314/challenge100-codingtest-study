#include <string>
#include <vector>

using namespace std;

int minval = 0;
int v[100];

bool isok(string cur, string comp) {
    int cnt = 0;
    for(int i=0; i<cur.size(); i++) {
        if(cur[i] != comp[i]) cnt++;
    }
    if(cnt == 1) return true;
    return false;
}

void dfs(int idx, int cnt, string tar, vector<string>words) {
    if(words[idx] == tar) {
        if(minval == 0 || minval > cnt)
            minval = cnt;
    }
    
    if(v[idx] == 0 || v[idx] > cnt) {
        v[idx] = cnt;
    }
    else return;
    
    for(int i=0; i<words.size(); i++) {
        if(idx == i) continue;
        if(isok(words[idx], words[i])) {
            dfs(i, cnt+1, tar, words);
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    // 1/22 15:23 ~ 15:33
    words.push_back(begin);
    dfs(words.size()-1, 0, target, words);
    return minval;
}