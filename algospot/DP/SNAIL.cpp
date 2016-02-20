#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

double dp[1002][2002];

int main() {
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	dp[0][0] = 1;
	for(int i=1; i<=1001; i++){
		for(int j=0; j<=2001; j++){
			dp[i][j+2] += dp[i-1][j] * 0.75;
			dp[i][j+1] += dp[i-1][j] * 0.25;
		}
	}

	int n, m;
	double ans;
	while(T--){
		cin >> n;
		cin >> m;
		ans = 0;
		for(int i=0; i<=2001; i++){
			if(i>=n) ans += dp[m][i];
		}
		printf("%.10f\n",ans);
	}
	return 0;
}
