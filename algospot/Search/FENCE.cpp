#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

vector<int> v;
int solve(int left, int right){
	if(left==right) return v[left];
	int mid = (left + right) / 2;
	int ans = max(solve(left, mid), solve(mid+1, right));
	int lo = mid;
	int hi = mid+1;
	int height = min(v[lo], v[hi]);
	ans = max(ans, height * 2);
	while(left < lo || hi < right){
		if(hi<right && (lo==left || v[lo-1] < v[hi+1])){
			hi++;
			height = min(height, v[hi]);
		}
		else{
			lo--;
			height = min(height, v[lo]);
		}
		ans = max(ans, height * (hi - lo + 1));
	}
	return ans;
}

int main() {
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;

	int n;
	while(T--){
		cin >> n;
		int height;
		v.clear();
		for(int i=0; i<n; i++){
			cin >> height;
			v.push_back(height);
		}

		cout << solve(0, v.size()-1) << endl;
	}
	return 0;
}
