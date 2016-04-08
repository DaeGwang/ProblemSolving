#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	int n;
	scanf("%d", &n);
	int a = 0;
	int b = 0;
	int c = -1;
	int s = n;
	int ans = 0;
	while(b*10 + c != n){
		a = s / 10;
		b = s % 10;
		c = (a + b) % 10;
		s = b*10 + c;
		ans++;
	}
	printf("%d",ans);
	return 0;
}

