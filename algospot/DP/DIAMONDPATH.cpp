#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;


int main() {
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;

	while(T--){
		int n;
		int data[300][300] = {};
		cin >> n;

		for(int i=0; i<2*n-1; i++){
			if(i<n){
				for(int j=0; j<=i; j++){
					cin >> data[i][j];
				}
			}
			else{
				for(int j=0; j<(2*n-i-1); j++){
					cin >> data[i][j];
				}
			}
		}

		for(int i=1; i<2*n-1; i++){
			if(i<n){
				for(int j=0; j<=i; j++){
					if(j!=0) data[i][j] += max(data[i-1][j-1], data[i-1][j]);
					else data[i][j] += data[i-1][j];
				}
			}
			else{
				for(int j=0; j<(2*n-i-1); j++){
					data[i][j] += max(data[i-1][j], data[i-1][j+1]);
				}
			}
		}
		cout << data[2*n-2][0] << endl;
	}
	return 0;
}
