#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    int now = 0;
    int in, out;
    int ans=0;
    for(int i=0; i<4; i++){
    	cin >> in >> out;
    	now = now-in+out;
    	if(ans<now) ans=now;
    }
    cout << ans << endl;
    return 0;
}
