#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	int arr[12] = {};
	
	cin >> n;
	
	for(int i=1; i<10; i++) arr[i] = -1;
	arr[10] = 11;

	for(int i=1; i<=n; i++) {
		int j=0;
		while(j<10) {
			if((arr[j+1] != -1 && arr[j+1] > arr[j]+1) 
				|| (arr[j+1] == -1 && arr[j]+1 < 10)) {
					arr[j]++;
					break;
			}
			else {
				if(arr[j+1] == -1) {
					// arr[j+1] = j+1;
					// arr[j] = j;
					for(int k=j+1; k>=0; k--)
						arr[k] = k;
					break;
				}
				else if(arr[j+1]+1 < 10 && (arr[j+2]==-1 || arr[j+2] > arr[j+1]+1)) {
					arr[j+1]++;
					arr[j] = j;
					for(int k=j; k>=0; k--)
						arr[k] = k;
					break;
				}
			}
			j++;
		}
		if(arr[9] == 10) {
			cout << -1;
			return 0;
		}

		// // for test
		// for(int i=9; i>=0; i--) {
		// 	if(arr[i] != -1)
		// 		cout << arr[i];
		// } cout << endl;
	}

	for(int i=9; i>=0; i--) {
		if(arr[i] != -1)
			cout << arr[i];
	} 
}