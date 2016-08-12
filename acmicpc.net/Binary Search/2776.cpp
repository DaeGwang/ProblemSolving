#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int dataN[1000001];
int n, m;

bool find(int number){
	int left = 0;
	int right = n-1;
	while(left<=right){
		int mid = (left+right)>>1;
		if(dataN[mid]==number) return true;
		if(dataN[mid]<number) left=mid+1;
		else right=mid-1;
	}
	return false;
}

int main() {
	freopen("input.txt", "r", stdin);
	int test_case;
	scanf("%d", &test_case);
	while(test_case--){
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d", &dataN[i]);
		}
		sort(dataN, dataN+n);
		scanf("%d", &m);
		int number;
		for(int i=0; i<m; i++){
			scanf("%d", &number);
			if(find(number)) printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}
