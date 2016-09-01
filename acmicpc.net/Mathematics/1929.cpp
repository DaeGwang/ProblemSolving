#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

int main()
{
    freopen("input.txt", "r", stdin);
    int n, m;
    int sieve[1000001];
    memset(sieve, -1, sizeof(sieve));
    sieve[1] = 0;
    for(int i=2; i*i<=1000000; i++){
    	if(sieve[i]==-1){
    		for(int j=i*i; j<=1000000; j+=i){
    			sieve[j] = 0;
    		}
    	}
    }

    scanf("%d", &n);
    scanf("%d", &m);

    for(int i=n; i<=m; i++){
    	if(sieve[i]==-1) printf("%d\n", i);
    }

    return 0;
}
