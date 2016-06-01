#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;
ll max(ll a, ll b){
	if(a>b) return a;
	else return b;
}
int main(){
    freopen("input.txt", "r", stdin);
    int n;
    int num;
    cin >> n;
    ll dp[100001];
    ll ans = 0;
    memset(dp, 0, sizeof(dp));
    cin >> num;
    dp[0] = num;
    ans = num;
    for(int i=1; i<=n-1; i++){
    	cin >> num;
    	dp[i] = max(dp[i-1] + num, num);
    	ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}

