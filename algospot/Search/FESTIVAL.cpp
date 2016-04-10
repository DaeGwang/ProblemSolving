#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <limits.h>
using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	int n, l;
	int data[1001];

	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &n, &l);
		double min = 1001;
		memset(data, 0, sizeof(data));
		for(int i=0; i<n; i++){
			scanf("%d", &data[i]);
		}
		for(int i=l; i<=n; i++){
			for(int j=0; j<=n-i; j++){
				int sum = 0;
				for(int k=0; k<i; k++){
					sum += data[j+k];
				}
				if(min > (double)sum/i){
					min = (double)sum/i;
				}
			}
		}
		printf("%.10f\n", min);
	}
    return 0;
}
