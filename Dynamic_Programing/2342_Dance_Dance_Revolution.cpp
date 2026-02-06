#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll dp[100001][5][5];
int movearr[5][5] = {
		{1,2,2,2,2},
		{0,1,3,4,3},
		{0,3,1,3,4},
		{0,4,3,1,3},
		{0,3,4,3,1}};

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 중앙에서 다른 지점으로 2
	// 인접한 지점으로 3
	// 반대 방향으로 4
	// 같은 지점 1

	int tmp, i;
	ll result;

	// 첫 번째 입력 처리
	cin >> tmp;
	dp[0][tmp][0] = 2;
	dp[0][0][tmp] = 2;

	// 이후 입력 처리
	for(i=1; ; i++) {
		cin >> tmp;
		if(tmp == 0) break;
		
		for(int a=0; a<5; a++) {
			for(int b=0; b<5; b++) {
				if(dp[i-1][a][b]) {
					// 왼발이 이동
					if(tmp != b) {
						result = dp[i-1][a][b] + movearr[a][tmp];
						if(dp[i][tmp][b] == 0 || dp[i][tmp][b] > result) 
							dp[i][tmp][b] = result;
					}
					
					// 오른발이 이동
					if(tmp != a) {
						result = dp[i-1][a][b] + movearr[b][tmp];
						if(dp[i][a][tmp] == 0 || dp[i][a][tmp] > result) 
							dp[i][a][tmp] = result;
					}
				}
			}
		}
	}

	// // for test
	// for(int k=0; k<i; k++) {
	// 	for(int a=0; a<5; a++) {
	// 		for(int b=0; b<5; b++) {
	// 			cout << dp[k][a][b] << " ";
	// 		} cout << endl;
	// 	} cout << endl << endl;
	// }
	
	int minval = -1;
	for(int a=0; a<5; a++) {
		for(int b=0; b<5; b++) {
			if(dp[i-1][a][b] != 0 && (minval == -1 || dp[i-1][a][b] < minval)) {
				minval = dp[i-1][a][b];
			}
		}
	}

	cout << minval;
}