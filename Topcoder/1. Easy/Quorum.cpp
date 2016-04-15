#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <limits.h>
using namespace std;

class Quorum {
public:
int count(vector<int> &v, int n);
};

int Quorum::count(vector<int> &v, int n) {
	int ans = 0;
	sort(v.begin(), v.end());
	for(int i=0; i<n; i++){
		ans += v[i];
	}
	return ans;
}

int main(){
	//freopen("input.txt", "r", stdin);

    return 0;
}
