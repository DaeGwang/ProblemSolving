#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


int main(){
    freopen("input.txt", "r", stdin);
    int n, m;
    int dp[301][301];
    cin >> n >> m;
    int num;
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=n; i++){
    	for(int j=1; j<=m; j++){
    		cin >> num;
    		dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + num;
    		//cout << dp[i][j] << " ";
    	}
    	//cout << endl;
    }
    cin >> n;
    int sx, sy, ex, ey;
    for(int i=0; i<n; i++){
    	cin >> sx >> sy >> ex >> ey;
    	cout << dp[ex][ey] - dp[ex][sy-1] - dp[sx-1][ey] + dp[sx-1][sy-1] << endl;
    }
    return 0;
}

