#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int n, m;
vector<double> v;

bool find(int k, double maxVal){
	int pos = 1;
	double now = v[0];
	for(int i=1; i<(int)v.size(); i++){
		if((v[i] - now) >= maxVal){
			pos++;
			now = v[i];
		}
	}
	if(pos < k) return false;
	else return true;
}

int main(){
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while(T--){
		cin >> m >> n;
		double dis;
		v.clear();
		for(int i=0; i<n; i++){
			cin >> dis;
			v.push_back(dis);
		}
		float lo = 0;
		float hi = 241;
		for(int it=0; it<100; it++){
			float mid = (hi+lo)/2.0;
			if(find(m, mid)){
				lo = mid;
			}
			else{
				hi = mid;
			}
		}
		printf("%.2f\n", hi);
    }
    return 0;
}

