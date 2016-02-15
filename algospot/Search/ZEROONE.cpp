#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	char s[1000001];
	int v[1000001];
	int n;
	int level = 0;

	scanf("%s",&s);
	v[0] = 0;
	for(int i=1; i<1000001; i++){
		if(s[i] == '\0') break;
		if(s[i] != s[i-1]) level++;
		v[i] = level;
	}
	int a, b;

	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d %d", &a, &b);
		if(v[a] != v[b]) printf("No\n");
		else printf("Yes\n");
	}

	return 0;
}
