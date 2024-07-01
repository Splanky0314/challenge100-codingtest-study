#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

typedef struct elem {
	int ratio;
	vector<int> rel;
} elem;

elem arr[10];
bool v[10] = {0, };

int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

int lcm(int a, int b) {
	return a*b/gcd(a,b);
}

void factori(int &a, int &b) {
	int tmp;
	if((tmp = gcd(a, b)) != 1) {
		a /= tmp;
		b /= tmp;
	}
}

void renew(int x, int k) {
	// cout << x << " " << k << "   ";
	v[x] = 1;
	arr[x].ratio *= k;
	// cout << "arr[" << x << "] = " << arr[x].ratio << endl;
	for(int y: arr[x].rel) {
		if(!v[y]) renew(y, k);
	}
	v[x] = 0;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, a, b, p, q;
	
	bool flag;
	int lcmvar;
	int target;

	cin >> n;

	for(int i=0; i<n-1; i++) {
		// cout << "<<" << i << endl;
		flag = 1;
		cin >> a >> b >> p >> q;
		factori(p, q);

		if(arr[a].rel.size() != 0) {
			// cout << "a is called" << endl;
			lcmvar = lcm(arr[a].ratio, p);
			if(arr[b].rel.size() != 0) {
				int tmp = lcm(arr[a].ratio, arr[b].ratio);
				int ra1 = tmp/arr[a].ratio*p;
				int ra2 = tmp/arr[b].ratio*q;
				// cout << ra1 << "||" << ra2 << endl;
				factori(ra1, ra2);
				renew(a, ra1);
				renew(b, ra2);
			}
			else  {
				arr[b].ratio = q*(lcmvar/p);
				renew(a, lcmvar/arr[a].ratio);
			}
			arr[a].rel.push_back(b);
			arr[b].rel.push_back(a);
			flag = 0;
		}
		else if(arr[b].rel.size() != 0) {
			// cout << "b is called" << endl;
			lcmvar = lcm(arr[b].ratio, q);
			
			arr[a].ratio = p*(lcmvar/q);
			renew(b, lcmvar/arr[b].ratio);
			
			arr[a].rel.push_back(b);
			arr[b].rel.push_back(a);
			flag = 0;
		}

		if(flag) {
			// cout << "new!\n";
			arr[a].ratio = p;
			arr[a].rel.push_back(b);
			arr[b].ratio = q;
			arr[b].rel.push_back(a);
		}
	}

	for(int i=0; i<n; i++) {
		cout << arr[i].ratio << " ";
	}
}