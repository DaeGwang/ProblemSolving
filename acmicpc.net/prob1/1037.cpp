#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int d[50];
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> d[i];
	}
	sort(d, d+n);
	cout << d[0] * d[n-1] << endl;

	return 0;
}

