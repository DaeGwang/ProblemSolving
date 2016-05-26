#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[10000][2];

int main(){
	freopen("input.txt", "r", stdin);
	int n;
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		dp[1][1] = 1;
		for(int i=2; i<=n; i++){
			dp[i][0] = dp[i-1][0] + dp[i-2][0];
			dp[i][1] = dp[i-1][1] + dp[i-2][1];
		}
		cout << dp[n][0] << " " << dp[n][1] << endl;
	}
    return 0;
}
