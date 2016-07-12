#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int d[501][501];
    int dp[501][501];
    memset(d, 0, sizeof(d));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            scanf("%d", &d[i][j]);
            dp[i][j] = max(d[i-1][j-1] + dp[i-1][j-1], d[i-1][j] + dp[i-1][j]);
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    int ans = 0;
    for(int i=1; i<=n; i++) ans = max(ans, dp[n][i]+d[n][i]);
    printf("%d\n", ans);

    return 0;
}