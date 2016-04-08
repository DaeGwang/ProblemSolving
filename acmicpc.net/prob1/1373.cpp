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
	//freopen("input.txt", "r", stdin);
	string a;
	cin >> a;
	int size = a.size();
	vector<int> v;
	for(int i=size-1; i>=0; i-=3){
		int num = 0;
		if(i>=0 && a[i]=='1') num += 1<<0;
		if(i-1>=0 && a[i-1]=='1') num += 1<<1;
		if(i-2>=0 && a[i-2]=='1') num += 1<<2;
		v.push_back(num);
	}
	for(int i=v.size()-1; i>=0; i--){
		printf("%d",v[i]);
	}
	return 0;
}

