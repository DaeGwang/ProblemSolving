#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

long long MAX = 2000000000;
int ratio(long long b, long long a){
	return (a*100) / b;
}
int solve(int n, int m){
	if(ratio(n, m) == ratio(n+MAX, m+MAX)) return -1;
	long long mid = 0;
	long long left = 0;
	long long right = MAX;
	while(left+1 < right){
		mid = (right+left)/2;
		if(ratio(n, m) == ratio(n+mid, m+mid)){
			left = mid;
		}
		else{
			right = mid;
		}
	}
	return right;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int T = 0;
	cin >> T;

	int n, m;
	while(T--){
		cin >> n >> m;
		cout << solve(n, m) << endl;
	}

	return 0;
}
