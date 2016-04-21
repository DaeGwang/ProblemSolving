#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    int n;
    int data[3][1001];
    int dp[3][1001];
    scanf("%d", &n);
    for(int i=0; i<n; i++){
    	scanf("%d", &data[0][i]);
    	scanf("%d", &data[1][i]);
    	scanf("%d", &data[2][i]);
    }
    dp[0][0] = data[0][0];
    dp[1][0] = data[1][0];
    dp[2][0] = data[2][0];
    for(int i=1; i<n; i++){
    	dp[0][i] = data[0][i] + min(dp[1][i-1], dp[2][i-1]);
    	dp[1][i] = data[1][i] + min(dp[0][i-1], dp[2][i-1]);
    	dp[2][i] = data[2][i] + min(dp[0][i-1], dp[1][i-1]);
    }
    printf("%d", min(dp[0][n-1], min(dp[1][n-1], dp[2][n-1])));
    return 0;
}
