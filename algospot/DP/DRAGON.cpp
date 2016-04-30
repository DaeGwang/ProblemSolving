#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int MAX = 1000000000+100;
int length[51];

void precalc(){
	length[0] = 1;
	for(int i=1; i<=50; i++){
		length[i] = min(MAX, length[i-1]*2 + 2);
	}
}
const string EXPAND_X = "X+YF";
const string EXPAND_Y = "FX-Y";

char expand(const string& s, int generations, int skip){
	if(generations == 0){
		return s[skip];
	}
	for(int i=0; i<(int)s.size(); i++){
		if(s[i] == 'X' || s[i] == 'Y'){
			if(skip >= length[generations]){
				skip-=length[generations];
			}
			else if(s[i]=='X'){
				return expand(EXPAND_X, generations-1, skip);
			}
			else{
				return expand(EXPAND_Y, generations-1, skip);
			}
		}
		else if(skip > 0){
			skip--;
		}
		else{
			return s[i];
		}
	}
	return '#';
}

int main(){
    freopen("input.txt", "r", stdin);
    precalc();
    int T;
	int n, p, l;
    cin >> T;
    while(T--){
		cin >> n >> p >> l;
		for(int i=p; i<p+l; i++){
			cout << expand("FX+YF",n,i-1);
		}
		cout << endl;
    }
    return 0;
}

