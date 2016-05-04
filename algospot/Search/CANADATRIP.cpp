#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int n, k;
int L[5001], M[5001], G[5001];
bool find(int length){
	int num = 0;
	for(int i=0; i<n; i++){
		if(length >= (L[i] - M[i]))
			num += (min(L[i],length) - (L[i] - M[i])) / G[i] + 1;
	}
	return (num >= k);
}
int main(){
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d",&T);
    while(T--){
		scanf("%d %d", &n, &k);
		for(int i=0; i<n; i++){
			scanf("%d %d %d", &L[i], &M[i], &G[i]);
		}
		int lo = -1;
		int hi = 8030000;
		while(lo+1<hi){
			int mid = (lo+hi)/2;
			if(find(mid)){
				hi=mid;
			}
			else{
				lo=mid;
			}
		}
		printf("%d\n", hi);
    }
    return 0;
}

