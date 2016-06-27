#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int m, n;
int ans;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int d[505][505];
int dp[505][505];

int find (int y, int x){
	int data;
	int& ret = dp[y][x];
	if(y==m && x==n) return 1;
	if(ret != -1) return ret;
	ret = 0;
	
	for(int i=0; i<4; i++){
		data = d[y+dy[i]][x+dx[i]];
		if(data!=-1 && data<d[y][x]){
			ret += find(y+dy[i], x+dx[i]);
		}
	}
	return ret;
}

int main(){
	freopen("input.txt", "r", stdin);

	scanf("%d %d", &m, &n);
	memset(d, -1, sizeof(d));
	memset(dp, -1, sizeof(dp));
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			scanf("%d", &d[i][j]);
		}
	}

	ans = find(1, 1);
	printf("%d\n", ans);

	return 0;
}