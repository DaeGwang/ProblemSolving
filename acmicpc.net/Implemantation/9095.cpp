#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[20];

int main(){
    freopen("input.txt", "r", stdin);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i=4; i<=11; i++){
    	dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    int t;
    int n;
    cin >> t;
    while(t--){
    	cin >> n;
    	cout << dp[n] << endl;
    }
    return 0;
}
