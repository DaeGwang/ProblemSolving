#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

struct Point{
	int x, y;
	int r;
	vector<Point*> children;
	Point(int _x, int _y, int _r): x(_x), y(_y), r(_r) {}
	int sqr(int n){
		return n * n;
	}
	bool has(Point& a){
		//return pow(x - a.x, 2) + pow(y - a.y, 2) < pow(r - a.r, 2);
		return sqr(x - a.x) + sqr(y - a.y) < sqr(r - a.r);
	}
	void add(Point* a){
		for(int i=0; i<(int)children.size(); i++){
			if(children[i]->has(*a)){
				children[i]->add(a);
				return;
			}
		}
		children.push_back(a);
	}
	int solve(int& m)
	{
		if (children.size() == 0) return 0;
		int m1 = 0, m2 = 0;
		for (int i=0; i<(int)children.size(); i++){
			m2 = max(m2, children[i]->solve(m) + 1);
			if (m2 > m1) swap(m1, m2);
		}
		m = max(m, m1 + m2);
		return m1;
	}
};

bool cmp(const Point &a, const Point &b){
	return a.r > b.r;
}

int main(){
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	int n;
	int x, y, r;
	vector<Point> v;
	while(T--){
		v.clear();
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d %d %d", &x, &y, &r);
			v.push_back(Point(x, y, r));
		}
		sort(v.begin(), v.end(), cmp);
		Point* root = &v[0];
		for(int i=1; i<(int)v.size(); i++){
			root->add(&v[i]);
		}
		int ans = 0;
		root->solve(ans);
		printf("%d\n", ans);
	}
    return 0;
}
