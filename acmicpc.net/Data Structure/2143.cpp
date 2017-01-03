#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int t;
    int n, m;
    int a[1005];
    int b[1005];
    int sumA[1000005];
    int sumB[1000005];
    int ak = 0;
    int bk = 0;
    long long ans = 0;
    scanf("%d", &t);
    scanf("%d", &n);
    for(int i=0; i<n; i++){
    	scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for(int i=0; i<m; i++){
    	scanf("%d", &b[i]);
    }
    for(int i=0; i<n; i++){
    	int sum = 0;
    	for(int j=i; j<n; j++){
    		sum += a[j];
    		sumA[ak++] = sum;
    	}
    }
    sort(sumA, sumA+ak);
    //sort(sumB, sumB+bk);
    for(int i=0; i<m; i++){
		int sum = 0;
		for(int j=i; j<m; j++){
			sum += b[j];
			sumB[bk++] = sum;
		}
	}
    for(int i=0; i<bk; i++){
    	ans += upper_bound(sumA, sumA + ak, t - sumB[i]) - lower_bound(sumA, sumA + ak, t - sumB[i]);
    }
    printf("%lld\n", ans);
    return 0;
}
