#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 14:40
    set<string> set;
    string input;
    int len;
    
    cin >> input;
    len = input.length();
    for(int i=0; i<len; i++) {
        for(int j=1; i+j<len+1; j++) {
            // i 부터 n개의 문자들 추출
            // cout << i << " " << j;
            // cout << input.substr(i, j) << endl;
            set.insert(input.substr(i, j));
        }
    }

    // for(auto it = set.begin(); it != set.end(); it++) {
    //     cout << (*it) << " ";
    // }

    cout << set.size();
}   