#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;

typedef struct Elem {
    int pr, kg;

    bool operator<(const Elem& other) const {
        if(pr != other.pr) return pr < other.pr;
        return kg > other.kg;
    }
} Elem;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // s#1000.. *g3..s3 !@$me
    int n, m; int kg, pr; 
    vector<Elem> arr;
    
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> kg >> pr;
        arr.push_back({pr, kg});
    }
    sort(arr.begin(), arr.end());

    // // for test
    // for(int i=0; i<n ;i++) {
    //     cout << arr[i].kg << " " << arr[i].pr << endl;
    // } cout << endl;

    int wei = 0, curcost = -1;

    for(int i=0; i<n; i++) {
        wei += arr[i].kg;

        if(i>0) {
            if(arr[i-1].pr == arr[i].pr) curcost += arr[i].pr;
            else curcost = arr[i].pr;
        } else curcost = arr[i].pr;
        
        if(wei >= m) {
            if(i == 0) cout << curcost;
            else if(arr[i-1].pr != arr[i].pr) cout << curcost;
            else {
                while(i<n && arr[i-1].pr == arr[i].pr) i++;
                if(i > n-1) cout << curcost;
                else cout << min(curcost, arr[i].pr);
                // cout << "test " <<i << "{}" << curcost << " / " << arr[i].pr << endl;
                
            }
            return 0;
        }
    }

    cout << -1;
}