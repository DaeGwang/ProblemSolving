#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[101];

int solve(int i){
	int mid = i/2;
	if(i==1 || i==2) return 0;
	if(i%2==1){
		return (dp[i] - dp[mid] + 1000000007) % 1000000007;
	}
	else{
		int ans = (dp[i] - dp[mid] + 1000000007) % 1000000007;
		ans = (ans - dp[mid-1] + 1000000007) % 1000000007;
		return ans;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for(int i=3; i<=100; i++){
		dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
	}


	int n;
	while(T--){
		cin >> n;
		cout << solve(n) << endl;
	}
}
