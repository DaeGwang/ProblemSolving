#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int ans = 0;
int n, a;
int data[101];

void dfs(int start, int step){
	if(step==0){
		ans += (data[start]==1);
	}
	else{
		if(start+step < n && start-step >= 0){
			if((data[start+step]==1) && (data[start-step]==1)) ans += 2;
		}
		else{
			if(start+step < n) ans += (data[start+step]==1);
			if(start-step >= 0) ans += (data[start-step]==1);
		}
	}
}

int main(){
    //freopen("input.txt", "r", stdin);
	cin >> n >> a;
	int num;
	for(int i=0; i<n; i++){
		cin >> num;
		data[i] = num;
	}
	for(int i=0; i<=n; i++){
		dfs(a-1, i);
	}
	cout << ans << endl;
    return 0;
}
