#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int dp[102][1002];
int w[102];
int s[102];
int n, m;
vector<string> v;

int pack(int capacity, int item){
	if(item==n) return 0;
	int& ret = dp[item][capacity];
	if(ret != -1) return ret;
	ret = pack(capacity, item+1);
	if(capacity >= s[item])
		ret = max(ret, pack(capacity - s[item], item+1) + w[item]);
	return ret;
}

void reconstruct(int capacity, int item, vector<string>& picked){
	if(item == n) return;
	if(pack(capacity, item) == pack(capacity, item+1)){
		reconstruct(capacity, item+1, picked);
	}
	else{
		picked.push_back(v[item]);
		reconstruct(capacity - s[item], item+1, picked);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;

	int size;
	int weight;
	string name;
	vector<string> picked;
	while(T--){

		cin >> n >> m;
		v.clear();
		picked.clear();
		for(int i=0; i<n; i++){
			cin >> name;
			cin >> size >> weight;
			v.push_back(name);
			s[i] = size;
			w[i] = weight;
		}
		for(int i=0; i<=n; i++){
			for(int j=0; j<=m; j++){
				dp[i][j] = -1;
			}
		}

		pack(m, 0);
		reconstruct(m, 0, picked);

		int pickSize = picked.size();
		cout << dp[0][m]  << " " << pickSize << endl;
		for(int i=0; i<pickSize; i++){
			cout << picked[i] << endl;
		}
	}
}
