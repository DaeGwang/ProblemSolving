#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
    freopen("input.txt", "r", stdin);
    int a, b;
    int n;
    cin >> a >> b;
    cin >> n;
    n+=b;
    a=(a+n/60)%24;
    b=n%60;
    cout << a << " " << b << endl;
    return 0;
}
