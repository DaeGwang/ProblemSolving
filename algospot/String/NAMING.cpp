#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

void solve(const string& s){
	int len = s.size();
	vector<int> pi(len, 0);
	int start = 1;
	int matched = 0;

	while(start + matched < len){
		if(s[start+matched] == s[matched]){
			matched ++;
			pi[start+matched-1] = matched;
		}
		else{
			if(matched == 0){
				start++;
			}
			else{
				start += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}

	int k = len;
	vector<int> ans;
	while(k>0){
		ans.push_back(k);
		k = pi[k-1];
	}
	for(int i=(int)ans.size()-1; i>=0; i--){
		cout << ans[i] << " ";
	}
	cout << endl;

}

int main()
{
	freopen("input.txt", "r", stdin);
	string a, b;
	cin >> a >> b;
	solve(a+b);
	return 0;
}

