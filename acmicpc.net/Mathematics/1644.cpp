#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
const int MAXN = 1000;
int n;
int chk[MAXN+1];
int p[MAXN+1];
int pcnt = 0;

int main(void)
{
    freopen("input.txt", "r", stdin);

    for(int i=2; i<=MAXN; i++){
		if(chk[i]==1) continue;
		p[pcnt++] = i;
		for(int j=i; j<=MAXN; j+=i){
			chk[j]=1;
		}
	}
    scanf("%d",&n);

    int ans = 0, low=0, high=0;
	int sum = 0;
	while(1){
		if(sum >= n) sum-=p[low++];
		else if(high == pcnt) break;
		else sum+=p[high++];
		if(sum==n) ans++;
	}
	printf("%d\n", ans);

    return 0;
}
