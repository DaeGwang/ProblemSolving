#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <limits.h>
using namespace std;

#define INF 987654321;
int ans;
int n, k, m, l;
int pre[13], semester[11];
int dp[13][1<<12];

int bitCount(int n){
	int cnt = 0;
	while(n>0){
		n &= n-1;
		cnt++;
	}
	return cnt;
}
int solve(int num, int now){
	if(bitCount(now)>=k) return 0;
	if(num>m) return INF;
	int ret = dp[num][now];
	if(ret != -1) return ret;
	ret = INF;
	int canTake = (semester[num] & ~now);
	for(int i=0; i<n; i++){
		if((canTake & (1<<i)) && ((now & pre[i]) != pre[i])){
			canTake &= ~(1<<i);
		}
	}
	for(int take = canTake; take>0; take = (take-1)&canTake){
		if(bitCount(take)>l) continue;
		ret = min(ret, solve(num+1, now | take) + 1);
	}
	ret = min(ret, solve(num+1, now));
	return ret;
}

int main(){
	freopen("input.txt", "r", stdin);
	int T;
	int maxNum = INF;

	scanf("%d", &T);
	while(T--){
		scanf("%d %d %d %d", &n, &k, &m, &l);
		memset(pre, 0, sizeof(pre));
		memset(dp, -1, sizeof(dp));
		memset(pre, 0, sizeof(pre));
		memset(semester, 0, sizeof(semester));
		int num, should;
		for(int i=0; i<n; i++){
			scanf("%d", &num);
			for(int j=0; j<num; j++){
				scanf("%d", &should);
				pre[i] |= (1<<should);
			}
		}
		for(int i=0; i<m; i++){
			scanf("%d", &num);
			for(int j=0; j<num; j++){
				scanf("%d", &should);
				semester[i] |= (1<<should);
			}
		}
		ans = solve(0, 0);
		if(ans==maxNum) printf("IMPOSSIBLE\n");
		else printf("%d\n", ans);
	}
    return 0;
}
