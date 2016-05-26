#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int dp[50];

int f(int n){
	if(n==0) return 0;
	if(n==1) return 1;
	int &ret = dp[n];
	if(ret != -1) return ret;
	ret = f(n-1) + f(n-2);
	return ret;
}
int main(){
    freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	int ans;
	memset(dp, -1, sizeof(dp));
	ans = f(n);
	printf("%d\n", ans);
    return 0;
}

