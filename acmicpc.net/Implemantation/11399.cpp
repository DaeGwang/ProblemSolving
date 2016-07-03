#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int data[1001];
    for(int i=0; i<n; i++){
    	cin >> data[i];
    }
    sort(data, data+n);
    int sum = 0;
    int ans = 0;
    for(int i=0; i<n; i++){
    	sum = sum + data[i];
    	ans += sum;
    }
    cout << ans << endl;
    return 0;
}