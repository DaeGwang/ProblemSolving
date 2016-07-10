#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    ll m;
    cin >> n >> m;
    int d[10005];
    for(int i=0; i<n; i++){
    	cin >> d[i];
    }

    int ans = 0;
    ll sum = 0;
    int start = 0;
    for(int i=0; i<n; i++){
    	sum += d[i];
    	while(sum>=m){
    		if(sum==m) ans++;
    		sum -= d[start++];
    	}
    }
    cout << ans << endl;

    return 0;
}
