#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits>
using namespace std;

int N,M;
int A[101],B[101];
int dp[101][101];

int jlis(int a, int b){
	int& ret = dp[a+1][b+1];
	if(ret != -1) return ret;
	ret = 2;
	int minNum = numeric_limits<int>::min();
	int maxA = (a==-1?minNum:A[a]);
	int maxB = (b==-1?minNum:B[b]);
	int maxElement = max(maxA, maxB);
	for(int i=a+1; i<N; i++){
		if(maxElement < A[i]){
			ret = max(ret, jlis(i, b)+1);
		}
	}
	for(int i=b+1; i<M; i++){
		if(maxElement < B[i]){
			ret = max(ret, jlis(a, i)+1);
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
		cin >> N >> M;
		for(int i=0; i<N; i++) cin >> A[i];
		for(int i=0; i<M; i++) cin >> B[i];
		for(int i=0; i<=N; i++){
			for(int j=0; j<=M; j++){
				dp[i][j] = -1;
			}
		}
		cout << jlis(-1, -1) - 2 << endl;
	}
}
