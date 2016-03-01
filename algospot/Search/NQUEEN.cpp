#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int data[20];
int n;
int ans;

bool isPossible(int row, int col){
	for(int i=0; i<row; i++){
		if(data[i] == col) return false;
		if(row-i == abs(col-data[i])) return false;
	}
	return true;
}

void nQueen(int row){
	if(row == n){
		ans++;
		return;
	}
	for(int i=0; i<n; i++){
		if(isPossible(row, i)){
			data[row] = i;
			nQueen(row+1);
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;

	while(T--){
		cin >> n;
		ans = 0;
		nQueen(0);
		cout << ans << endl;
	}

	return 0;
}
