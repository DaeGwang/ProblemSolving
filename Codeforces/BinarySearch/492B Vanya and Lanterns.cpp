#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

double a[1001];
int n, l;

bool f(double d){
	if(a[0]-0>d) return false;
	for(int i=1; i<n; i++){
		if(a[i]-a[i-1]>2*d) return false;
	}
	if(l-a[n-1]>d) return false;
	return true;
}

int main(){
    //freopen("input.txt", "r", stdin);
    cin >> n >> l;
    for(int i=0; i<n; i++){
    	cin >> a[i];
    }
    sort(a, a+n);
    double lo = -1;
    double hi = 1000000000;
    for(int i=0; i<100; i++){
    	double mid = (lo+hi)/2;
    	if(f(mid)){
    		hi = mid;
    	}
    	else{
    		lo = mid;
    	}
    }
    printf("%.10f\n",hi);
    return 0;
}

