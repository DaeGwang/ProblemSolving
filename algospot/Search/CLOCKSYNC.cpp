#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int INF = 9999;
const char con[10][17] = {
"xxx.............",
"...x...x.x.x....",
"....x.....x...xx",
"x...xxxx........",
"......xxx.x.x...",
"x.x...........xx",
"...x..........xx",
"....xx.x......xx",
".xxxxx..........",
"...xxx...x...x.."
};

bool isAnswer(vector<int>& table){
	for(int i=0; i<16; i++){
		if(table[i] != 12) return false;
	}
	return true;
}
void click(vector<int>& table, int swit){
	for(int i=0; i<16; i++){
		if(con[swit][i] == 'x'){
			table[i] += 3;
			if(table[i]==15) table[i] = 3;
		}
	}
}
int search(vector<int>& table, int swit){
	if(swit==10){
		if(isAnswer(table)) return 0;
		else return INF;
	}
	int ret = INF;
	for(int i=0; i<4; i++){
		ret = min(ret, i + search(table, swit+1));
		click(table, swit);
	}
	return ret;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;

	int data;
	int ans;
	vector<int> table;
	while(T--){
		table.clear();
		for(int i=0; i<16; i++){
			cin >> data;
			table.push_back(data);
		}
		ans = search(table, 0);
		if(ans == INF) cout << -1 << endl;
		else cout << ans << endl;
	}
}
