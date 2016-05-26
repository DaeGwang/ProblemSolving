#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


int main(){
    freopen("input.txt", "r", stdin);
    int a, b, c;
    int sum = 0;
    c = 1;
    cin >> a >> b;
    while(b>0){
    	cout << a * (b % 10) << endl;
    	sum += (a * (b % 10)) * c;
    	b /= 10;
    	c *= 10;
    }
    cout << sum;
    return 0;
}

