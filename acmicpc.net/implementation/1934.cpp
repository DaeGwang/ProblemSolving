#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b, a%b);
}
int main()
{
	freopen("input.txt", "r", stdin);
	int a, b;
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%d %d",&a,&b);
		printf("%d\n",(a*b)/gcd(a,b));
	}
	return 0;
}

