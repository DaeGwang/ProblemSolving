#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
    freopen("input.txt", "r", stdin);
    int n;
    int m;
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        vector<int> minv;
        vector<int> maxv;
        int location;
        int length;
        for(int i=0; i<m; i++){
            scanf("%d", &location);
            length = n - location;
            minv.push_back(min(length, location));
            maxv.push_back(max(length, location));
        }
        sort(minv.begin(), minv.end());
        sort(maxv.begin(), maxv.end());
        printf("%d %d\n", minv[minv.size()-1], maxv[maxv.size()-1]);

    }
    return 0;
}