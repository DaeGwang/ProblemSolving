#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[101][101];
int way[101][101];
int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;

	int n;
	while(T--){

	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			cin >> dp[i][j];
		}
	}

	way[0][0] = 1;
	for(int i=1; i<n; i++){
		for(int j=0; j<=i; j++){
			if(j==0){
				dp[i][j] += dp[i-1][j];
				way[i][j] = way[i-1][j];
			}
			else {
				dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
				if(dp[i-1][j-1] == dp[i-1][j]) way[i][j] = way[i-1][j-1] + way[i-1][j];
				else{
					if(dp[i-1][j-1] > dp[i-1][j]){
						way[i][j] = way[i-1][j-1];
					}
					else{
						way[i][j] = way[i-1][j];
					}

				}
			}
		}
	}
/*
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			cout << way[i][j] << " ";
		}
		cout << endl;
	}
*/
	int max = 0;
	for(int i=0; i<=n; i++){
		if(max < dp[n-1][i]) max = dp[n-1][i];
	}
	int ans = 0;
	for(int i=0; i<=n; i++){
		if(max == dp[n-1][i]) ans += way[n-1][i];
	}
	cout << ans << endl;

	}
}
