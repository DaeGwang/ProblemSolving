#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

vector<string> names;
vector<int> ans;
int w[105];
int v[105];
int dp[105][1005];
int n, m;

int main(){
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while(T--){
		cin >> n >> m;
		names.clear();
		ans.clear();
		string name;
		memset(dp, 0, sizeof(dp));
		for(int i=0; i<n; i++){
			cin >> name;
			names.push_back(name);
			cin >> w[i] >> v[i];
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<=m; j++){
				if(j<w[i]) dp[i+1][j] = dp[i][j];
				else dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]]+v[i]);
			}
		}
		int i=n;
		int j=m;
		while(i>0){
			if(dp[i][j]!=dp[i-1][j]){
				ans.push_back(i-1);
				j-=w[i-1];
			}
			i--;
		}
		cout << dp[n][m] << " " << ans.size() <<  endl;
		for(int i=(int)ans.size()-1; i>=0; i--){
			cout << names[ans[i]] << endl;
		}
    }
    return 0;
}

