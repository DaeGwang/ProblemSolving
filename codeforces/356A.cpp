#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(){
    //freopen("input.txt", "r", stdin);
    int chk[101];
    memset(chk, 0, sizeof(chk));
    int num;
    int ans = 0;
    vector<int> v;
    for(int i=0; i<=4; i++){
    	cin >> num;
    	chk[num]+= num;
    	v.push_back(num);
    	if(chk[num] != 0 && chk[num] != num){
    		if(chk[ans] < chk[num]) ans = num;
    	}
    }
    int sum = 0;
    int removed = 0;
    for(int i=0; i<=4; i++){
    	if(v[i] != ans){
    		sum += v[i];
    	}
    	else{
    		removed++;
    		if(removed>3) sum += v[i];
    	}
    }
    cout << sum << endl;
    return 0;
}
