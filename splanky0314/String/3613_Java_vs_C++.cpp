#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long;

bool isJava(string str) {
	/*
	첫 단어 소문자, 이후 단어부터 첫 문자만 대문자. 다 붙여씀
	*/
	
	if(isupper(str[0])) return false;
	if(str.find('_') != string::npos) {
		return false;
	}
	return true;
}

bool isCpp(string str) {
	/*
	소문자만 사용, _사용 -> 걍 대문자만 없으면 되는거아님?
	*/
	bool space = false;
	if(str[0] == '_' || str[str.length()-1] == '_') return false; // 이게 맞나?
	for(int i=0; i<str.length(); i++) {
		if(str[i] == '_') {
			if(space) return false; // _ 2연속
			else space = true;
		}
		else if(isupper(str[i])) return false;
		else space = false;
	}
	return true;
}

void cpp2java(string str) {
	bool upper = false;
	for(int i=0; i<str.length(); i++) {
		if(str[i] == '_') upper = true;
		else {
			if(upper) {
				cout << char(toupper(str[i]));
				upper = false;
			}
			else {
				cout << str[i];
			}
		}
	}
}

void java2cpp(string str) {
	for(int i=0; i<str.length(); i++) {
		if(isupper(str[i])) {
			cout << '_' << char(tolower(str[i]));
		}
		else cout << str[i];
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// s#1000.. *g3..s3 !@$me
	string s;
	cin >> s;

	if(isJava(s)) {
		java2cpp(s);
	}
	else if(isCpp(s)) {
		cpp2java(s);
	}
	else {
		cout << "Error!";
	}
}