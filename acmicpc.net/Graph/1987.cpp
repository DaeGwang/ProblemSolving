#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int ans;
int chk[200];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int n, m;
char d[30][30];

void dfs(int y, int x, int step){
	if(ans<step) ans=step;
	chk[(int)d[y][x]] = 1;
	for(int i=0; i<4; i++){
		if(y+dy[i] >=0 && y+dy[i] < n && x+dx[i] >= 0 && x+dx[i] < m){
			if(chk[(int)d[y+dy[i]][x+dx[i]]] == 0){
				dfs(y+dy[i], x+dx[i], step+1);
			}
		}
	}
	chk[(int)d[y][x]] = 0;
}


int main(){
    freopen("input.txt", "r", stdin);
    string s;

    cin >> n >> m;
    memset(chk, 0, sizeof(chk));
    memset(d, 0, sizeof(d));
    ans = 0;
    for(int i=0; i<n; i++){
    	cin >> s;
    	for(int j=0; j<m; j++){
    		d[i][j] = s[j];
    	}
    }

    dfs(0, 0, 1);
    cout << ans << endl;

    return 0;
}
