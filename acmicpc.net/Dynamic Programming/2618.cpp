#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int E[1010][2];
int tr[1010][1010];
int dp[1010][1010];

int dis(int a, int b) {
	return abs(E[a][0]-E[b][0])+abs(E[a][1]-E[b][1]);
}

int f(int a, int b) {
	int next=(a>b?a:b)+1;
	if(next>=m+2) return 0;
	int &res = dp[a][b];
	if(res != -1) return res;

	int aVal = f(next,b)+dis(a,next);
	int bVal = f(a,next)+dis(b,next);
	res = min(aVal, bVal);
	if(aVal <= bVal) tr[a][b] = 1;
	else tr[a][b] = 2;
	return res;
}

int main(){
    //freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    memset(dp, -1, sizeof(dp));
    E[0][0]=E[0][1]=1;
    E[1][0]=E[1][1]=n;
    for(int i=2; i<m+2; i++) scanf("%d %d", &E[i][0], &E[i][1]);
    printf("%d\n", f(0,1));
    int sx = 0;
    int sy = 1;
    for(int i=2; i<=m+1; i++){
    	printf("%d\n", tr[sx][sy]);
    	int next=(sx>sy?sx:sy)+1;
    	if(tr[sx][sy]==1) sx=next;
    	else sy=next;
    }
    return 0;
}
