#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	vector<int> v;
	int n, m, num;
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	scanf("%d",&m);
	for(int i=0; i<m; i++){
		scanf("%d",&num);
		int left = 0;
		int right = v.size()-1;
		int mid = 0;
		while(right-left>1){
			mid = (left+right)/2;
			if(v[mid]>num) right = mid;
			else left = mid;
		}
		if(v[left]==num || v[right]==num) printf("1\n");
		else printf("0\n");
	}

	return 0;
}

