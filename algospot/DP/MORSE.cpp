#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

const int MAX = 205;
int n, m;
int bi[MAX][MAX];
const int M = 1000000000+100;
void init(){
	memset(bi, 0, sizeof(bi));
	for(int i=0; i<MAX; i++){
		bi[i][0] = bi[i][i] = 1;
		for(int j=1; j<i; j++){
			bi[i][j] = min(M, bi[i-1][j-1] + bi[i-1][j]);
		}
	}
}

string solve(int n, int m, int k){
	if(n==0){
		return string(m, 'o');
	}
	int now = bi[n+m-1][n-1];
	if(k < now) return "-" + solve(n-1, m, k);
	return "o" + solve(n, m-1, k-now);
}

int main(){
    freopen("input.txt", "r", stdin);
    int T, k;
    init();
    cin >> T;
    while(T--){
		cin >> n >> m >> k;
		cout << solve(n, m, k-1) << endl;
    }
    return 0;
}

