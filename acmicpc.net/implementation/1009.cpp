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
	int a, b;
	scanf("%d", &n);
	while(n--){
		scanf("%d %d", &a, &b);
		int sum = 1;
		while(b--){
			sum *= a;
			sum %= 10;
		}
		if(sum==0) printf("10\n");
		else printf("%d\n",sum);
	}
	return 0;
}

