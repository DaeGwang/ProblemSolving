#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

string N;
int dp[10002];
const int INF = 987654321;

int cal(int start, int end){
	string M = N.substr(start, end-start+1);
	if(M==string(M.size(), M[0])) return 1;
	bool progressive = true;
	for(int i=0; i<M.size()-1; i++){
		if(M[i+1] - M[i] != M[1] - M[0]) progressive = false;
	}
	if(progressive && abs(M[1]-M[0]) == 1) return 2;
	bool alternating = true;
	for(int i=0; i<M.size(); i++){
		if(M[i] != M[i%2]) alternating = false;
	}
	if(alternating) return 4;
	if(progressive) return 5;
	return 10;
}

int search(int start)
{
	if(start == N.size()) return 0;
	int& ret = dp[start];
	if(ret != -1) return ret;
	ret = INF;
	for(int i=3; i<=5; i++){
		if(start + i <= N.size()){
			ret = min(ret, search(start + i) + cal(start, start + i - 1));
		}
	}
	return ret;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;

	while(T--){
		cin >> N;
		for(int i=0; i<N.size(); i++){
			dp[i] = -1;
		}
		cout << search(0) << endl;
	}
}
