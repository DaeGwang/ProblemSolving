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
    cin >> n;
    vector<int> v;
    int num;
    int id = 0;
    for(int i=0; i<n; i++){
    	cin >> num;
    	id += num;
    	v.push_back(id);
    }
    int m;
    cin >> m;
    int ans = 0;
    for(int i=0; i<m; i++){
    	cin >> num;
    	vector<int>::iterator it = lower_bound(v.begin(), v.end(), num);
    	ans = it - v.begin() + 1;
    	cout << ans << endl;
    }
    return 0;
}

