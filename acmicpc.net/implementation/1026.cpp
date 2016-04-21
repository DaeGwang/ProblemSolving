#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	int a[51];
	int b[51];
	int n;
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<n; i++) cin >> b[i];

	sort(a, a+n);
	sort(b, b+n);

	int s = 0;
	for(int i=0; i<n; i++) s += a[i] * b[n-i-1];
	cout << s << endl;

	return 0;
}

