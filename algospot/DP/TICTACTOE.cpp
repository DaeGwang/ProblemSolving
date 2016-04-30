#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int dp[20000];
//map<vector<string>, int> m;

bool isFinished(const vector<string> &v, char now){
	int x, y;
	for(int i=0; i<3; i++){
		x = 0, y = 0;
		for(int j=0; j<3; j++){
			if(v[i][j] == now){
				x++;
				if(x==3) return true;
			}
			if(v[j][i] == now){
				y++;
				if(y==3) return true;
			}
		}
	}
	if (v[0][0] == v[1][1] && v[1][1] == v[2][2] && v[2][2] == now){ return true; }
	if (v[0][2] == v[1][1] && v[1][1] == v[2][0] && v[2][0] == now){ return true; }

	return false;
}
int bijection(const vector<string>& board) {
	int ret = 0;
	for (int y = 0; y < 3; y++){
		for (int x = 0; x < 3; x++){
			ret *= 3;
			if (board[y][x] == 'o') ret += 1;
			if (board[y][x] == 'x') ret += 2;
		}
	}
	return ret;
}

int canWin(vector<string> &v, char now){
	char enemy = 'x' + 'o' - now;
	if(isFinished(v, enemy)) return -1;
	//if(m.count(v)) return m[v];
	//int& ret = m[v];
	int& ret = dp[bijection(v)];
	if(ret != -2) return ret;
	int minValue = 2;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(v[i][j]=='.'){
				v[i][j] = now;
				minValue = min(minValue, canWin(v, enemy));
				v[i][j] = '.';
			}
		}
	}
	if(minValue==2 || minValue==0) return ret=0;
	return ret = -minValue;
}

void init(){
	for(int i=0; i<20000; i++)
		dp[i] = -2;
}
int main(){
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
	vector<string> v;
	init();
    while(T--){
		string s;
		int num = 0;
		v.clear();
		for(int i=0; i<3; i++){
			cin >> s;
			for(int j=0; j<3; j++){
				if(s[j]!='.') num++;
			}
			v.push_back(s);
		}
		char turn = num%2==0 ? 'x' : 'o';
		int ans = canWin(v, turn);

		if(ans==0){
			cout << "TIE" << endl;
		}
		else if(ans==-1){
			cout << (turn=='o' ? 'x' : 'o') << endl;
		}
		else{
			cout << turn << endl;
		}

    }
    return 0;
}

