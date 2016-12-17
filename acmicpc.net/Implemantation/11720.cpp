#include<stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	int sum = 0;
	char c;
	for(int i=0; i<n; i++){
		scanf(" %c", &c);
		sum += (c-'0');
	}
	printf("%d\n", sum);


	return 0;
}
