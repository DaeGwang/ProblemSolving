#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dpA[1001][1001];
int dpB[1001][1001];
int a[1001];
int b[1001];

int main()
{
	//freopen("input.txt", "r", stdin);
	int n = 0;

	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	for(int i=0; i<n; i++){
		scanf("%d",&b[i]);
	}
	int maxVal = 0;
	int maxL = 0;
	int maxR = 0;
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if(j==0) dpA[i][j] = a[0];
			else dpA[i][j] = dpA[i][j-1] | a[j];

			if(j==0) dpB[i][j] = b[0];
			else dpB[i][j] = dpB[i][j-1] | b[j];

			if(maxVal < dpA[i][j] + dpB[i][j]){
				maxVal = dpA[i][j] + dpB[i][j];
				maxL = i;
				maxR = j;
			}
		}
	}
	printf("%d\n", maxVal);
	return 0;
}
