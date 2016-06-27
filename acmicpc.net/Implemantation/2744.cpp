#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

void solve(string s){
	for(int i=0; i<(int)s.size(); i++){
		if(s[i] >= 'a' && s[i] <= 'z') cout << (char)(s[i] + ('A' - 'a'));
		else cout << (char)(s[i] - ('A' - 'a'));
	}
}

int main(){
    freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    solve(s);
    return 0;
}

