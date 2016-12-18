#include<stdio.h>

int d[1001][1001];
int checked[1001];
int ans;
int n, m;

void dfs(int num){
	if(checked[num]==1) return;
	checked[num] = 1;
	for(int i=1; i<=n; i++){
		if(d[num][i] == 1){
			dfs(i);
		}
	}
}

int main()
{
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    int from, to;
    for(int i=0; i<m; i++){
    	scanf("%d %d", &from, &to);
    	d[from][to] = 1;
    	d[to][from] = 1;
    }
    ans = 0;
    for(int i=1; i<=n; i++){
    	if(checked[i]==0){
    		dfs(i);
    		ans++;
    	}
    }
    printf("%d\n", ans);
	return 0;
}
