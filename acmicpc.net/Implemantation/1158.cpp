#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

int check[5001];

int main()
{
    freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n;
    cin >> k;
    vector<int> v;
    int now = 0;
    for(int i=0; i<n; i++){
    	int pass = 0;
    	while(pass!=k){
    		if(now==n) now=1;
    		else now++;
    		if(check[now]==0) pass++;
    	}
    	check[now] = 1;
    	v.push_back(now);
    }

    cout << "<";
    for(int i=0; i<(int)v.size(); i++){
    	if(i==(int)v.size()-1) cout << v[i] << ">" << endl;
    	else cout << v[i] << ", ";
    }
    return 0;
}
