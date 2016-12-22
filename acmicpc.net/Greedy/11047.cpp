#include <stdio.h>
#include <algorithm>
using namespace std;

int d[10];

int main()
{
    freopen("input.txt", "r", stdin);
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++) scanf("%d", &d[i]);
    int ans = 0;
    int s = n-1;
    while(s>=0){
		ans += k/d[s];
		k = k % d[s];
		if(k%d[s]==0) break;
		if(s>0){
			s--;
		}
    }
    printf("%d\n", ans);
    return 0;
}
