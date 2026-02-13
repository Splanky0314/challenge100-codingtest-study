#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

// 아이디어가 정말 안떠올랐던 문제..

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, tmp;
    vector<int> arr; // arr[수 i] = 위치

    cin >> n; arr.resize(n+1);
    for(int i=0; i<n; i++) {
        cin >> tmp; arr[tmp] = i;
    }

    // 가장 긴 증가하는 부분 수열
    int maxlen = 0;
    for(int i=1; i<=n; ) {
        // cout << "i: " << i << endl;
        int len = 1; 
        for(int j=i; j<n; j++) {
            if(arr[j] < arr[j+1]) {
                len++;
            }
            else break;
        }
        if(maxlen < len) maxlen = len;
        i += len;
    }

    // // for test
    // for(int i=1; i<=n; i++) {
    //     cout << arr[i] << " ";
    // }
    cout << n - maxlen;
}

/*
와 초간결 답안 - 이건 진짜머리 잘써야...

int n, num;
cin >> n;
// dp[i]: 숫자 i로 끝나는 연속된 번호의 길이
vector<int> dp(n + 1, 0); 
int max_len = 0;

for (int i = 0; i < n; i++) {
    cin >> num;
    // 숫자 num이 들어왔을 때, num-1까지 만들어진 길이에 나를 붙인다!
    dp[num] = dp[num - 1] + 1; 
    max_len = max(max_len, dp[num]);
}
cout << n - max_len;

*/