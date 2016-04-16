#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <limits.h>
using namespace std;

#define MAXN 100005
int data[MAXN];
int psum[MAXN];
long long cnt[MAXN];
int n, k;

void init(){
	memset(psum, 0, sizeof(psum));
	psum[0] = 0;
	for(int i=1; i<=n; i++){
		scanf("%d", &data[i]);
		psum[i] = (psum[i-1] + data[i]) % k;
	}
}
int solve1(){
	const int mod = 20091101;
	int ret = 0;
	memset(cnt, 0, sizeof(cnt));
	for(int i=0; i<=n; i++){
		cnt[psum[i]]++;
	}
	for(int i=0; i<k; i++){
		if(cnt[i] >= 2) ret = (ret + ((cnt[i] * (cnt[i]-1)) / 2)) % mod;
	}
	return ret;
}
int solve2(){
	vector<int> dp(n+1, 0);
	vector<int> track(k, -1);
	for(int i=0; i<=n; i++){
		if(i>0) dp[i] = dp[i-1];
		else dp[i] = 0;

		int loc = track[psum[i]];
		if(loc != -1) dp[i] = max(dp[i], dp[loc]+1);
		track[psum[i]] = i;
	}
	return dp.back();
}

int main(){
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &n, &k);
		init();
		printf("%d %d\n", solve1(), solve2());
	}
    return 0;
}
