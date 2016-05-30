#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int biSearch(const vector<int>& A, int x){
	int n = A.size();
	int left = -1, right = n;
	while(left + 1 < right){
		int mid = (left + right) / 2;
		if(A[mid] < x){
			left = mid;
		}
		else{
			right = mid;
		}
	}
	return right;
}

int main(){
	//freopen("input.txt", "r", stdin);
    return 0;
}
