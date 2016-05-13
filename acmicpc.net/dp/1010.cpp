#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int dp[31][31];

int build(int left, int right){
	if(left==1) return right;
	if(left==0 || right==0) return 0;
	int& ret = dp[left][right];
	if(ret != -1) return ret;
	ret = build(left-1, right-1) + build(left, right-1);
	return ret;
}
int main(){
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    memset(dp, -1, sizeof(dp));
    int a, b;
    while(T--){
    	scanf("%d %d", &a, &b);
    	printf("%d\n", build(a, b));
    }
    return 0;
}

