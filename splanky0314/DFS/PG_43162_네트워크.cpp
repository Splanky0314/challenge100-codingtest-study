#include <string>
#include <vector>

using namespace std;

bool v[201];

void solve(int x, int n, vector<vector<int>> coms) {
    v[x] = true;
    for(int j=0; j<n; j++) {
        if(coms[x][j] && !v[j]) { // 연결
            solve(j, n, coms);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    // 1/22 15:02 ~ 15:07 : 5min
    
    int answer = 0;
    for(int i=0; i<n; i++) {
        if(!v[i]) {
            solve(i, n, computers);
            answer++;
        }
    }
    
    return answer;
}