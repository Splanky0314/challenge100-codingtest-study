#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dp[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    
    for(int i=0; i<triangle.size(); i++) {
        for(int j=0; j<=i; j++) {
            dp[i][j] += triangle[i][j];
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
        }
    }
    
    for(int i=0; i<triangle.size(); i++) {
        answer = max(answer, dp[triangle.size()-1][i]);
    }
    
//     /// for test
//     for(int i=0; i<triangle.size(); i++) {
//         for(int j=0; j<=i; j++) {
//             cout << dp[i][j] << " ";
//         }cout << endl;
//     }
    
    return answer;
}