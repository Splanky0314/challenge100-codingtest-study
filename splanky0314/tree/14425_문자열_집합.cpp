#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

class Node {
public:
	Node *next[26];
	bool isleaf;
	Node(): isleaf(false) {
		fill(next, &next[25], nullptr);
	}
	~Node() {
		for(auto& child : next) {
			delete child;
		}
	}

	void insert(const char* key) {
		if(*key == 0) isleaf = true;
		else {
			int next_idx = *key - 'a';
			if(next[next_idx] == nullptr) {
				next[next_idx] = new Node();
			}
			next[next_idx] -> insert(key + 1);
		}
	}

	Node* find(const char* key) {
		if(*key == 0) return this;
		int next_idx = *key - 'a';
		if(next[next_idx] == nullptr) {
			return nullptr;
		}
		return next[next_idx]->find(key+1);
	}
};

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	Node* root = new Node();
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		char tmp[501];
		cin >> tmp;
		root->insert(tmp);
	}
	int cnt = 0;
	for(int i=0; i<m; i++) {
		char tmp[501];
		cin >> tmp;
		Node* result = root->find(tmp);
		if(result && result->isleaf) {
			cnt++;
		}
	}
	cout << cnt;
}