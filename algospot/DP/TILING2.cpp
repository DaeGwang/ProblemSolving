#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[101];

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
		cout << dp[n] << endl;
	}
}
