#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    int d[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    map<string, int> m;
    m["Sunday"] = 1;
    m["Monday"] = 2;
    m["Tuesday"] = 3;
    m["Wednesday"] = 4;
    m["Thursday"] = 5;
    m["Friday"] = 6;
    m["Saturday"] = 7;
    int month, day;
    string s;
    int T;
    cin >> T;
    while(T--){
		cin >> month >> day;
		cin >> s;
		int now = m[s];
		while(now>1){
			if(day == 1){
				if(month==1) month=12;
				else month--;
				day = d[month]+1;
			}
			day--;
			now--;
		}
		for(int i=0; i<7; i++){
			cout << day << " ";
			if(d[month]==day){
				day=0;
				if(month==12) month=1;
				else month++;
			}
			day++;
		}
		cout << endl;
    }
    return 0;
}

