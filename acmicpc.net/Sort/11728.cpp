#include <stdio.h>
#include <algorithm>
#define M 1000005
using namespace std;
int n, m;
int a[M], b[M], c[2*M];
int main()
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
	for(int i=0; i<m; i++) scanf("%d", &b[i]);
	int k = 0;
	int ka = 0;
	int kb = 0;
	while(ka<n && kb<m){
		if(a[ka]<b[kb]) c[k++] = a[ka++];
		else c[k++] = b[kb++];
	}
	while(ka<n) c[k++] = a[ka++];
	while(kb<m) c[k++] = b[kb++];
	for(int i=0; i<n+m; i++) printf("%d ", c[i]);
    return 0;
}
