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
	int cnt3, cnt1;
	
	cin >> n;

	cnt3 = n/3;
	cnt1 = n%3;
	
	if((cnt3 + cnt1)%2 == 1) 
		cout << "SK";
	else 
		cout << "CY";
}