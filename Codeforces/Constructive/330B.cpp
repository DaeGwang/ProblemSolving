#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    int m;
    cin >> n >> m;
    int a, b;
    int d[1001];
    memset(d, 0, sizeof(d));
    for(int i=0; i<m; i++){
    	cin >> a >> b;
    	d[a] = 1;
    	d[b] = 1;
    }
    int k = 1;
    while(d[k] == 1) k++;
    cout << n-1 << endl;
    for(int i=1; i<=n; i++){
    	if(i!=k) cout << i << " " << k << endl;
    }
    return 0;
}

