#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

vector<int> makePi(const string &s){
	int n = s.length();
	vector<int> pi(n, 0);
	int matched = 0;
	for(int i=1; i<n; i++){
		while(matched > 0 && s[matched] != s[i]){
			matched = pi[matched-1];
		}
		if(s[matched]==s[i]) matched++;
		pi[i] = matched;
	}
	return pi;
}
void search(const string &s, const string &k){
	int n = s.length();
	vector<int> pi = makePi(k);
	int matched = 0;
	for(int i=0; i<n; i++){
		while(matched >0 && s[i] != k[matched]){
			matched = pi[matched-1];
		}
		if(s[i] == k[matched]){
			if(i==n-1){
				printf("%d\n", n+i-matched);
				return;
			}
			matched++;
		}
	}
}
int main(){
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--){
		string s;
		string key;
		cin >> s;
		key = s;
		reverse(key.begin(), key.end());
		search(s, key);
    }
    return 0;
}

