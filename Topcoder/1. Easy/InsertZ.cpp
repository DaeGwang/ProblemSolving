#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <limits.h>
using namespace std;

class InsertZ  {
public:
string canTransform (string a, string b);
};

string InsertZ ::canTransform (string a, string b) {
	int aLen = a.length();
	int bLen = b.length();
	int now = 0;
	for(int i=0; i<bLen; i++){
		if(now==aLen){
			if(b[i]!='z') return "No";
		}
		else{
			if(b[i]!='z'){
				if(a[now]!=b[i]) return "No";
				now++;
			}
		}
	}
	if(now==aLen) return "Yes";
	else return "No";
}

int main(){
	freopen("input.txt", "r", stdin);
	string a, b;
	cin >> a >> b;
	InsertZ in;
	cout << in.canTransform(a, b) << endl;
    return 0;
}
