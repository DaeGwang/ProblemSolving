#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <limits.h>
using namespace std;

struct RNG{
	int seed;
	RNG(): seed(1983) {}
	unsigned next(){
		unsigned ret = seed;
		seed = ((seed * 214013u) + 2531011u);
		return ret % 10000 + 1;
	}
};

int main(){
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while(T--){
		RNG r;
		int k, n;
		scanf("%d %d", &k, &n);
		long long psum = 0;
		int ans = 0;
		queue<long long> q;
		for(int i=0; i<n; i++){
			psum += r.next();
			q.push(psum);
			while(q.front() + k < psum) q.pop();
			if(q.front()+k == psum) ans++;
		}
		printf("%d\n", ans);
	}
    return 0;
}
