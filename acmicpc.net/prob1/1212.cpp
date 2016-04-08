#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	string a;
	cin >> a;
	int size = a.size();
	vector<int> v;
	for(int i=size-1; i>=0; i--){
		int target = a[i] - '0';
		for(int j=0; j<3; j++){
			if(target&1) v.push_back(1);
			else{
				if(i==0 && !target) break;
				v.push_back(0);
			}
			target = target>>1;
		}
	}
	for(int i=v.size()-1; i>=0; i--){
		printf("%d",v[i]);
	}
	return 0;
}

