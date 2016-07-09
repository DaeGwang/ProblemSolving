#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int ans;
int n;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int chk[101][101];
int d[101][101];
int k;

void dfs(int y, int x){
	chk[y][x] = 1;
	for(int i=0; i<4; i++){
		if(y+dy[i]>=0 && y+dy[i]<n && x+dx[i]>=0 && x+dx[i]<n){
			if(chk[y+dy[i]][x+dx[i]] == 0 && d[y+dy[i]][x+dx[i]]>k){
				dfs(y+dy[i], x+dx[i]);
			}
		}
	}

}

int main(){
    freopen("input.txt", "r", stdin);

    cin >> n;
    memset(d, 0, sizeof(d));
    for(int i=0; i<n; i++){
    	for(int j=0; j<n; j++){
    		cin >> d[i][j];
    	}
    }
    int count = 0;
    int ans = 0;
    for(k=0; k<=100; k++){
        memset(chk, 0, sizeof(chk));
        count = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(chk[i][j] == 0 && d[i][j] > k){
					dfs(i, j);
					count++;
				}
			}
		}
		if(ans<count) ans=count;
    }
    cout << ans << endl;

    return 0;
}
