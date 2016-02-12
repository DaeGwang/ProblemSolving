#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int data[50];
int dp[50][50];
int n;
int find(int left, int right){
	int score;
	if(left > right) return 0;
	if(dp[left][right] != 0) return dp[left][right];
	score = max(data[left] - find(left+1, right), data[right] - find(left, right-1));
	if(right - left >= 2){
		score = max(score, -find(left+2, right));
		score = max(score, -find(left, right-2));
	}
	dp[left][right] = score;
	//cout << left << " " << right << " " << score << endl;
	return score;
}

int main() {
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;


	while(T--){
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> data[i];
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				dp[i][j] = 0;
			}
		}
		cout << find(0, n-1) << endl;
	}
	return 0;
}
