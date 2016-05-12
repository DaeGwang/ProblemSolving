#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int table[5001][5001];

int main()
{
	freopen("input.txt", "r", stdin);
	int n = 0;
	int m = 0;
	int k = 0;
	int type = 0;
	int num = 0;
	int color = 0;

	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&k);
	for(int i=0; i<=n; i++){
		for(int j=0; j<=m; j++){
			table[i][j] = 0;
		}
	}
	for(int i=0; i<k; i++){
		scanf("%d",&type);
		scanf("%d",&num);
		scanf("%d",&color);
		if(type == 1){
			for(int i=1; i<=m; i++)
				table[num][i] = color;
		}
		else if(type == 2){
			for(int i=1; i<=n; i++)
				table[i][num] = color;
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(j==m) printf("%d\n",table[i][j]);
			else printf("%d ",table[i][j]);
		}
	}
	return 0;
}
