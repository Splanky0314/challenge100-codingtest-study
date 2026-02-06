#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool v[100000];
vector<vector<string>> result;

void dfs(int idx, vector<string> ans, vector<vector<string>> ticks) {
    bool isfinished = true;
    for(int i=0; i<ticks.size(); i++) {
        if(!v[i]) {
            isfinished = false;
            if(ticks[idx][1] == ticks[i][0]) {
                v[i] = true;
                vector<string> tmp = ans;
                tmp.push_back(ticks[i][1]);
                dfs(i, tmp, ticks);
                // v[i] = false;
            }
        }
    }
    if(isfinished) {
        result.push_back(ans);
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    // 1/22 15:35 ~ 16:05
    vector<string> ans;
    
    sort(tickets.begin(), tickets.end());
    // for(int i=0; i<tickets.size(); i++) {
    //     for(int j=0; j<2; j++){
    //         cout << tickets[i][j] << " ";
    //     } cout << endl;
    // } cout << endl;
    
    for(int i=0; i<tickets.size(); i++) {
        if("ICN" == tickets[i][0]) {
            v[i] = true;
            vector<string> tmp; tmp.push_back("ICN"); tmp.push_back(tickets[i][1]);
            dfs(i, tmp, tickets);
            // v[i] = false;
        }
    }
    
    return result[0];
}