#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


int main(){
    freopen("input.txt", "r", stdin);

    vector<pair<int, int> > v;
    int n = 9;
    //scanf("%d", &n);
    int num;
    for(int i=1; i<=n; i++){
    	scanf("%d", &num);
    	v.push_back(make_pair(num, i));
    }
    sort(v.begin(), v.end());
    printf("%d\n", v[v.size()-1].first);
    printf("%d\n", v[v.size()-1].second);
    return 0;
}

