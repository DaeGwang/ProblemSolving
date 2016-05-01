#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int n, m, price[20], pref[20];
int c[201];
int sushi(){
	int ret = 0;
	c[0] = 0;
	for(int budget = 1; budget <= m; budget++){
		int cand = 0;
		for(int dish = 0; dish < n; dish++){
			if(budget >= price[dish]){
				cand = max(cand, c[(budget - price[dish])%201] + pref[dish]);
			}
		}
		c[budget % 201] = cand;
		ret = max(ret, cand);
	}
	return ret;

}
int main(){
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while(T--){
		cin >> n >> m;
		m /= 100;
		int pri, pre;
		for(int i=0; i<n; i++){
			cin >> pri >> pre;
			price[i] = pri/100;
			pref[i] = pre;
		}
		int ans = sushi();
		cout << ans << endl;
    }
    return 0;
}

