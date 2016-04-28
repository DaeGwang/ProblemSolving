#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

const int MAX = 15;
const double INF = 987654321;
double d[MAX][MAX];
double cache[MAX][1<<MAX];
int n;

double find(int here, int visited){
	if(visited==(1<<n)-1) return 0;
	double& ret = cache[here][visited];
	if(ret>0) return ret;
	ret = INF;
	for(int there=0; there<n; there++){
		if((visited & (1<<there)) == 0){
			ret = min(ret, find(there, visited + (1<<there)) + d[here][there]);
		}
	}
	return ret;
}


int main(){
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while(T--){
		cin >> n;
		memset(d, 0, sizeof(d));
		memset(cache, 0, sizeof(cache));
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin >> d[i][j];
			}
		}
		double ans = INF;
		for(int i=0; i<n; i++){
			ans = min(ans, find(i, 0));
		}
		printf("%.10f\n", ans);
    }
    return 0;
}

