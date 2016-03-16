#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n, k;
int user[1001];
int kill(int num){
	int current = num;
	int curK = 0;
	while(true){
		if(user[current]==1){
			if(curK==k-1){
				user[current] = 0;
				return current;
			}
			curK++;
		}
		if(current+1 == n) current = 0;
		else current++;
	}
	return current;
}
int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		cin >> k;
		for(int i=0; i<n; i++){
			user[i] = 1;
		}
		int next = 0;
		user[0] = 0;
		for(int i=0; i<n-3; i++){
			next = kill(next);
		}
		for(int i=0; i<n; i++){
			if(user[i]==1) cout << i+1 << " ";
		}
		cout << endl;
	}
	return 0;
}

