#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int ans;

void find(int n, int step){
	if(step > ans) return;
	if(n==1){
		if(ans > step) ans = step;
	}
	if(n%3==0) find(n/3, step+1);
	if(n%2==0) find(n/2, step+1);
	find(n-1, step+1);
}

int main(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    ans = 1000001;
    find(n, 0);
    printf("%d", ans);
    return 0;
}
