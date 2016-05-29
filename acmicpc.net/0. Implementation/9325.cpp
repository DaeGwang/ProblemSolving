#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


int main(){
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    int s;
    int n;
    int p, q;
    while(T--){
    	cin >> s;
    	cin >> n;
    	for(int i=0; i<n; i++){
    		cin >> p >> q;
    		s += (p*q);
    	}
    	cout << s << endl;
    }
    return 0;
}

