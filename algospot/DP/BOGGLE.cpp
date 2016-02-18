#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

bool dp[6][6][11];
char data[6][6];
int length;
string s;
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

bool isBound(int x, int y){
	if(x>=0 && x<=4 && y>=0 && y<=4) return true;
	else return false;
}

bool find(int i, int j, int len){
	if(len == length) return true;
	if(!dp[i][j][len]) return false;
	for(int c=0; c<8; c++){
		if(isBound(i+dx[c],j+dy[c]) && data[i+dx[c]][j+dy[c]] == s[len]){
			if(find(i+dx[c],j+dy[c],len+1)) return true;
		}
	}
	dp[i][j][len] = false;
	return false;
}
bool solve(){
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			if( data[i][j] == s[0]){
				if( find(i, j, 1) ) return true;
			}
		}
	}
	return false;
}
int main() {
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;
	int n;

	while(T--){

		for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				//scanf("%s", &data[i]);
				cin >> data[i][j];
			}
		}
		cin >> n;

		for(int test=0; test<n; test++){
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					for(int k=0; k<10; k++){
						dp[i][j][k] = true;
					}
				}
			}
			cin >> s;
			length = s.length();

			if(solve()) cout << s << " YES" << endl;
			else cout << s << " NO" << endl;
		}
	}
	return 0;
}
