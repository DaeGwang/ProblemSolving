#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    map<vector<int>, int> m;
    vector<int> a;
    vector<int> b;
    for(int i=1; i<=8; i++) a.push_back(i);
    for(int i=8; i>=1; i--) b.push_back(i);

    m[a] = 1;
    m[b] = 2;
    vector<int> d(8);
    for(int i=0; i<8; i++){
    	scanf("%d", &d[i]);
    }
    if(m.count(d)==0) printf("mixed");
    else if(m[d]==1) printf("ascending");
    else if(m[d]==2) printf("descending");
    return 0;
}

