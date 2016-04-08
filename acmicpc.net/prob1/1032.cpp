#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	char d[51][51];
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> d[i];
	}
	int k=0;
	while(d[0][k]!=0){
		char base = d[0][k];
		bool isSame = true;
		for(int i=1; i<n; i++){
			if(d[i][k]!=base){
				isSame = false;
				continue;
			}
		}
		if(isSame) cout << base;
		else cout << '?';
		k++;
	}
	cout << endl;

	return 0;
}

