#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int data[200001];
int val[200001];
int ans[200001];
int main()
{
	//freopen("input.txt", "r", stdin);
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	for(int i=0; i<n; i++){
		scanf("%d", &data[i]);
	}
	int order = 0;
	int number = 0;
	val[m-1] = 0;
	for(int i=1; i<=m; i++){
		scanf("%d",&order);
		scanf("%d",&number);
		if(order==1) val[number-1] = i;
		else val[number-1] = -(i);
	}
	int start = 0;
	int end = n-1;
	int current = 0;
	bool desc = true;
	for(int i=n-1; i>=0; i--){
		if(val[i] !=0 && abs(val[i])>=current){
			current = abs(val[i]);
			if(val[i] < 0) desc = false;
			else desc = true;
		}
		if(desc){
			ans[i] = data[end];
			end--;
		}
		else{
			ans[i] = data[start];
			start++;
		}
	}
	for(int i=0; i<n; i++){
		if(i!=n-1) printf("%d ",ans[i]);
		else printf("%d\n",ans[i]);
	}
	return 0;
}
