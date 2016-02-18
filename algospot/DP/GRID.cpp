#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int a[1001], b[1001], c[1001];
int main() {
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	a[0]=0;  a[1]=1;  a[2]=5;
	b[0]=0;  b[1]=1;  b[2]=2;
	c[0]=0;  c[1]=0;  c[2]=1;
	for(int i=3; i<=1000; i++){
		c[i] = a[i-2]+c[i-2];
		b[i] = a[i-1]+b[i-1];
		a[i] = a[i-2]+a[i-1]+2*b[i-1]+c[i];
	}

	int n;
	for(int i=1; i<=T; i++){
		cin >> n;
		cout << i << " " << a[n] << endl;
	}
	return 0;
}
