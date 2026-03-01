#include <string>
#include <vector>
#include <iostream>
#define MOD 1000000007

using namespace std;

int dx[] = {1, 0};
int dy[] = {0, 1};

bool map[101][101];
int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    if(puddles.size() == 0) return n*m;
    
    for(int i=0; i<puddles.size(); i++) {
        map[puddles[i][1]][puddles[i][0]] = 1;
    }
    
    dp[1][1] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            
            for(int k=0; k<2; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if(1<=nx&&nx<=n&&1<=ny&&ny<=m && map[nx][ny] != 1) {
                    dp[nx][ny] = (dp[nx][ny] + dp[i][j]) % MOD;   
                }
            }
            
        }
    }
    
    // for test
    // for(int i=1; i<=n; i++) {
    //     for(int j=1; j<=m; j++) {
    //         cout << dp[i][j] << " "; 
    //     } cout << endl;
    // }
    
    answer = dp[n][m];
    
    return answer;
}