#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int n, k;
int dp[101][11];
const int INF = 987654321;

int A[101], pSum[101], pSqSum[101];

void precalc(){
	sort(A, A+n);
	pSum[0] = A[0];
	pSqSum[0] = A[0] * A[0];
	for(int i=1; i<n; i++){
		pSum[i] = pSum[i-1] + A[i];
		pSqSum[i] = pSqSum[i-1] + A[i] * A[i];
	}
}

int calc(int lo, int hi){
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo-1]);
	int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo-1]);
	int m = int(0.5 + (double)sum / (hi - lo + 1));
	int ret = sqSum - 2 * m * sum + m * m * (hi - lo + 1);
	return ret;
}

int solve(int from, int k){
	if(from==n) return 0;
	if(k==0) return INF;
	int& ret = dp[from][k];
	if(ret!=-1) return ret;
	ret = INF;
	for(int i=from; i<n; i++){
		ret = min(ret, calc(from, i) + solve(i+1, k-1));
	}
	return ret;
}

int main(){
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while(T--){
        cin >> n >> k;
        for(int i=0; i<n; i++){
        	cin >> A[i];
        }
        memset(dp, -1, sizeof(dp));
        precalc();
        int ans = solve(0, k);
        cout << ans << endl;
    }
    return 0;
}

