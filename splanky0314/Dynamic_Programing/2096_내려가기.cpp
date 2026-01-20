#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
int map[100001][3];
int maxdp[2][3];
int mindp[2][3];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	fill(&mindp[0][0], &mindp[n][2], 1000001);
	for(int i=0; i<n; i++) 
		cin >> map[i][0] >> map[i][1] >> map[i][2];
	
	for(int i=0; i<3; i++) { // init
		maxdp[1][i] = map[n-1][i];
		mindp[1][i] = map[n-1][i];
		maxdp[0][i] = 0;
		mindp[0][i] = 10000001;
	}

	for(int i=n-1; i>0; i--) {
		for(int j=0; j<3; j++) {
			if(0<=j-1) {
				if(maxdp[0][j-1] < map[i-1][j-1] + maxdp[1][j]) {
					maxdp[0][j-1] = map[i-1][j-1] + maxdp[1][j];
				}
				if(mindp[0][j-1] > map[i-1][j-1] + mindp[1][j]) {
					mindp[0][j-1] = map[i-1][j-1] + mindp[1][j];
				}
			}
			if(maxdp[0][j] < map[i-1][j] + maxdp[1][j]) {
				maxdp[0][j] = map[i-1][j] + maxdp[1][j];
			}
			if(mindp[0][j] > map[i-1][j] + mindp[1][j]) {
				mindp[0][j] = map[i-1][j] + mindp[1][j];
			}
			if(j+1<=2) {
				if(maxdp[0][j+1] < map[i-1][j+1] + maxdp[1][j]) {
					maxdp[0][j+1] = map[i-1][j+1] + maxdp[1][j];
				}
				if(mindp[0][j+1] > map[i-1][j+1] + mindp[1][j]) {
					mindp[0][j+1] = map[i-1][j+1] + mindp[1][j];
				}
			}
		}

		// up
		for(int j=0; j<3; j++) {
			maxdp[1][j] = maxdp[0][j];
			mindp[1][j] = mindp[0][j];
			maxdp[0][j] = 0;
			mindp[0][j] = 10000001;
		}
	}


	int maxval = 0, minval = 10000001;
	for(int j=0; j<3; j++) {
		if(maxval < maxdp[1][j]) 
			maxval = maxdp[1][j];
		if(minval > mindp[1][j])
			minval = mindp[1][j];
	}

	cout << maxval << " " << minval;
}