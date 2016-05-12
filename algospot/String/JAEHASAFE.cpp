#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

vector<int> makePi(string s){
	int len = s.length();
	vector<int> pi(len+1, 0);
	int matched = 0;
	for(int i=1; i<len; i++){
		while(matched > 0 && s[matched] != s[i]){
			matched = pi[matched-1];
		}
		if(s[i]==s[matched]) matched++;
		pi[i] = matched;
	}
	return pi;
}

vector<int> KMP(string s, string p){
	int n = s.length(), m = p.length();
	vector<int> ret;
	vector<int> pi = makePi(p);
	int matched = 0;
	for(int i=0; i<n; i++){
		while(matched > 0 && p[matched] != s[i]){
			matched = pi[matched-1];
		}
		if(s[i]==p[matched]){
			matched++;
			if(matched==m){
				ret.push_back(i-m+1);
				matched = pi[matched-1];
			}
		}
	}
	return ret;
}
int shifts(const string& original, const string& target){
	return KMP(original+original, target)[0];
}
int main(){
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while(T--){
		int n;
		cin >> n;
		string a, b;
		cin >> a;
		int ans = 0;
		for(int i=0; i<n; i++){
			cin >> b;
			if(i%2==1) ans+= shifts(a, b);
			else ans+= shifts(b, a);
			a = b;
		}
		cout << ans << endl;
    }
    return 0;
}

