#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MOD 10007

using namespace std;
using ll = long long;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 3/3 Tue 22:58
    // 첫 시도..
    // ll maxval = 0;
    // cin >> n;
    // for(int len=1; len<=n; len++) {
    //     ll result = 1;
    //     int remain = n % len;
    //     int quotient = n / len;

    //     for(int k=0; k<remain; k++) 
    //         // result = result * (quotient + 1) % MOD;
    //         result = result * (quotient + 1);
    //     for(int k=0; k<len-remain; k++)
    //         // result = result * quotient % MOD;  
    //         result = result * quotient;
        
    //     // maxval = max(maxval, result);
    //     cout << len << ": " << result << endl;
    //     if(maxval < result) maxval = result;
    //     else if(maxval >= result) break;
    // }

    // cout << maxval % MOD;

    /*
    수학적 특성..
    e(2.7~)에 가까운 수를 곱할 수록 최대로 커짐
    */

    cin >> n;

    int quotient = n/3;
    int remain = n%3;
    int result = 1;
    
    if(n == 0) {
        cout << 0; return 0;
    }
    if(n == 1) {
        cout << 1; return 0;
    }

    if(remain == 0) {
        for(int i=0; i<quotient; i++) {
            result = (result * 3) % MOD;
        }
    }
    else if(remain == 1) {
        for(int i=0; i<quotient-1; i++) {
            result = (result * 3) % MOD;
        }
        result = (result * 2) % MOD;
        result = (result * 2) % MOD;
    }
    else if(remain == 2) {
        for(int i=0; i<quotient; i++) {
            result = (result * 3) % MOD;
        }
        result = (result * 2) % MOD; 
    }

    cout << result;
}

