#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int day[13];
	char key[7][100] = {
			"SUN","MON","TUE","WED","THU","FRI","SAT"
	};
	int n, m;
	day[0] = 0;
	day[1] = mon[0];
	for(int i=2; i<13; i++){
		day[i] = day[i-1] + mon[i-1];
	}
	scanf("%d %d",&n, &m);
	printf("%s",key[(day[n-1]+m)%7]);

	return 0;
}

