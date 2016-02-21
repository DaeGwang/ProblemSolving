#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

string W, S;
int dp[101][101];
bool matched(int w, int s){
	int& ret = dp[w][s];
	if(ret != -1) return ret;
	if(w==W.size()) return ret = (s == S.size());
	if(w<W.size() && s<S.size() && (W[w] == '?' || W[w] == S[s])) return ret = matched(w+1, s+1);
	if(W[w] == '*'){
		if(matched(w+1, s) || (s<S.size() && matched(w, s+1))) return ret = 1;
	}
	return ret = 0;
}
int main() {
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;
	int n;
	vector<string> ans;
	while(T--){
		cin >> W;
		cin >> n;
		ans.clear();
		while(n--){
			for(int i=0; i<101; i++){
				for(int j=0; j<101; j++){
					dp[i][j] = -1;
				}
			}
			cin >> S;
			if(matched(0,0)){
				ans.push_back(S);
			}
		}
		sort(ans.begin(), ans.end());
		for(int i=0; i<ans.size(); i++){
			cout << ans[i] << endl;
		}
	}
	return 0;
}
