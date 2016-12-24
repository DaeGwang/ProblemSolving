#include <stdio.h>
#include <algorithm>
using namespace std;

int n, m;
int d[500001];

int search(int num){
	int l = 0;
	int r = n-1;
	int mid;
	while(l<=r){
		mid = (l+r)/2;
		if(d[mid]==num){
			return 1;
		}
		if(d[mid]<num) l=mid+1;
		else r=mid-1;
	}
	return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &d[i]);
    sort(d, d+n);
    scanf("%d", &m);
    int num;
    for(int i=0; i<m; i++){
    	scanf("%d", &num);
    	printf("%d\n", search(num));
    }
    return 0;
}
