#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

bool chk[1000];
double d[1000];
double ans;

struct Point{
	double x;
	double y;
};

double getDistance(Point a, Point b){
	return sqrt(pow(a.x - b.x, 2.0) + pow(a.y - b.y , 2.0));
}

int main() {
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;

	int n;
	vector<Point> v;

	while(T--){

		cin >> n;
		v.clear();
		for(int i=0; i<n; i++){
			d[i] = 2000;
			chk[i] = false;
		}

		for(int i=0; i<n; i++){
			Point p;
			cin >> p.x >> p.y;
			v.push_back(p);
		}

		int now = 0;
		d[0] = 0;
		ans = 0;
		for(int i=0; i<n; i++){
			double min = 2000;
			int minCord = 0;
			for(int j=0; j<n; j++){
				if(!chk[j] && d[j] < min){
					min = d[j];
					minCord = j;
				}
			}
			if(min != 0 && ans < min) ans = min;

			//cout << min << endl;
			now = minCord;
			chk[now] = true;
			for(int j=0; j<n; j++){
				if(!chk[j] && getDistance(v[now], v[j]) < d[j]){
					d[j] = getDistance(v[now], v[j]);
				}
			}
		}
		printf("%.2f\n", ans);
	}
	return 0;
}
