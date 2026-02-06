#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
char tree[100000000];
int indexarr[50];

int returnidx(char a) {
	return indexarr[a-'A'];
}

void preorder(int x) {
	if(!tree[x]) return;
	cout << tree[x];
	preorder(x*2);
	preorder(x*2+1);
}

void inorder(int x) {
	if(!tree[x]) return;
	inorder(x*2);
	cout << tree[x];
	inorder(x*2+1);
}

void postorder(int x) {
	if(!tree[x]) return;
	postorder(x*2);
	postorder(x*2+1);
	cout << tree[x];
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int idx = 1;
	char a, b, c;
	cin >> n;
	indexarr[0] = 1; // A가 항상 root이므로
	tree[1] = 'A';
	for(int i=0; i<n; i++) {
		cin >> a >> b >> c;
		idx = returnidx(a);
		// cout << a << " = " << idx;
		if(b != '.') {
			tree[idx*2] = b;
			indexarr[b-'A'] = idx*2;
			// cout << b << " = " << idx*2;
		}
		if(c != '.') {
			tree[idx*2+1] = c;
			indexarr[c-'A'] = idx*2+1;
			// cout << c << " = " << idx*2+1;
		}
	}

	// cout << endl;
	// for(int i=0; i<20; i++) {
	// 	if(!tree[i]) cout << ". ";
	// 	else cout << tree[i] << " ";
	// } cout << endl;

	preorder(1); cout << "\n";
	inorder(1); cout << "\n";
	postorder(1);
}