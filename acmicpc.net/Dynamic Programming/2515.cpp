#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
struct picture{
	int value;
	int height;
	picture(){
		value = 0;
		height = 0;
	}
	picture(int value, int height): value(value), height(height) {}
};
bool cmp(picture a, picture b){
	if(a.height==b.height) return a.value > b.value;
	else return a.height < b.height;
}
int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    int s;
    cin >> n >> s;
    vector<picture> d(n+1);
    int dp[300001];
    int value, height;
    for(int i=1; i<=n; i++){
    	scanf("%d %d", &height, &value);
    	d[i].value = value;
    	d[i].height = height;
    }
    sort(d.begin(), d.end(), cmp);
    int maxValue = 0;
    int k = 0;
    int ans = 0;
    for(int i=1; i<=n; i++){
    	for(; k<i && d[i].height-d[k].height>=s; k++){
			maxValue = max(maxValue, dp[k]);
    	}
		dp[i] = d[i].value + maxValue;
		ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}
