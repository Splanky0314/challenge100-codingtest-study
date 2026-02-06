#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, tmp, sum = 0;
	vector<ll> arr;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> tmp;
		if(tmp > 0) {
			sum += tmp;
		}
		else if(tmp == 0) {
			arr.push_back(tmp);
		}
		else if(sum != 0) {
			arr.push_back(sum);
			sum = 0;
			arr.push_back(tmp);
		}
		else {
			arr.push_back(tmp);
		}
	}
	if(sum != 0) arr.push_back(sum);

	// // for test
	// for(int i=0; i<arr.size(); i++) {
	// 	cout << arr[i] << " ";
	// } cout << endl << endl;

	// left dp 생성
	vector<int> left(arr.size());
	left[0] = arr[0];

	// cout << "LEFT DP" << endl; // for test
	// cout << left[0] << " ";

	for(int i=1; i<left.size(); i++) {
		if(left[i-1] > 0)
			left[i] = left[i-1] + arr[i];
		else 
			left[i] = arr[i];	
		
		// cout << left[i] << " "; // for test
	}

	// right dp 생성
	vector<int> right(arr.size());
	right[right.size()-1] = arr[right.size()-1];

	// cout << endl << "RIGHT DP" << endl; // for test

	for(int i=right.size()-2; i>=0; i--) {
		if(right[i+1] > 0)
			right[i] = right[i+1] + arr[i];
		else 
			right[i] = arr[i];
	}
	
	// // for test
	// for(int i=0; i<right.size(); i++) {
	// 	cout << right[i] << " ";
	// } cout << endl << endl;


	int maxval = -100000001; 
	int onlypositive = true;
	// 없앨 -를 기준으로 잡고 / -가 없으면 제거하지 않는거지
	for(int i=0; i<arr.size(); i++) {
		if(arr[i] <= 0) {
			onlypositive = false;
			sum = left[i] + right[i] - arr[i] * 2;
			// cout << sum << " "; // for test

			// -만 들어온 경우 처리,
			if(left[i] == arr[i] && arr[i] == right[i]) sum = arr[i];
			if(maxval < sum) maxval = sum;
		}
	}

	if(onlypositive)
		cout << left[0];
	else
		cout << maxval;
}