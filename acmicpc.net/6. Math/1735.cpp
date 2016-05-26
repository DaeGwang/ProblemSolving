#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int gcd(int a, int b){
	if(a % b == 0) return b;
	else return gcd(b, a % b);
}

int main(){
	freopen("input.txt", "r", stdin);

	int a, b, c, d;
	scanf("%d %d", &a, &b);
	scanf("%d %d", &c, &d);

	int ansA = b*c + a*d;
	int ansB = b*d;
	int gcdNumber = gcd(ansA, ansB);
	printf("%d ", ansA/gcdNumber);
	printf("%d", ansB/gcdNumber);

    return 0;
}
