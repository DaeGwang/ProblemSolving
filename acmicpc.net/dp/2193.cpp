#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    long long dp[2][100];
    dp[0][0] = 0;
    dp[1][0] = 1;

    for(int i=1; i<=n; i++){
    	dp[0][i] = dp[0][i-1] + dp[1][i-1];
    	dp[1][i] = dp[0][i-1];
    }

    printf("%lld", dp[0][n-1] + dp[1][n-1]);
    return 0;
}

