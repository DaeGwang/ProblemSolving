#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;
	int n;
	int data[101][101];
	while(T--){
		cin >> n;
		for(int i=0; i<n; i++){
			for(int j=0; j<=i; j++){
				cin >> data[i][j];
			}
		}
		for(int i=1; i<n; i++){
			for(int j=0; j<=i; j++){
				if(j==0){
					data[i][j] += data[i-1][j];
				}
				else{
					data[i][j] += max(data[i-1][j-1], data[i-1][j]);
				}
			}
		}
		int max = 0;
		for(int i=0; i<n; i++){
			if(max < data[n-1][i]) max = data[n-1][i];
		}
		cout << max << endl;

	}
	return 0;
}
