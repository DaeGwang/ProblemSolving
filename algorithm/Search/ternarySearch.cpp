#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long func(long long n){
	return n;
}

void triSearch(){
	long long left = 1;
	long long right = 1000000;

	while(left+5<right){
		long long a = (2 * left + right) / 3;
		long long b = (left + 2 * right) / 3;
		if(func(a) < func(b)){
			right = b;
		}
		else{
			left = a;
		}
	}
	long long ans = func(left);
	for(int i=left+1; i<=right; i++){
		ans = min(ans, func(i));
	}
}


int main(){
	freopen("input.txt", "r", stdin);
    return 0;
}
