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
    int n;
    int sieve[1001];
    memset(sieve, -1, sizeof(sieve));
    sieve[1] = 0;
    for(int i=2; i<=100; i++){
    	if(sieve[i]==-1){
    		for(int j=i*i; j<=1001; j+=i){
    			sieve[j] = 0;
    		}
    	}
    }

    scanf("%d", &n);
    int num;
    int ans = 0;
    for(int i=0; i<n; i++){
    	scanf("%d", &num);
    	if(sieve[num]==-1) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
