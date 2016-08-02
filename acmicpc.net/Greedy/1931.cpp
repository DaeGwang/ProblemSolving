#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int main()
{
    freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	vector<pair<int, int> > v;
	int start, end;
	for(int i=0; i<n; i++){
		cin >> start >> end;
		v.push_back(make_pair(end, start));
	}
	sort(v.begin(), v.end());
	int time = v[0].first;
	int ans = 1;
	for(int i=1; i<(int)v.size(); i++){
		if(v[i].second >= time){
			ans++;
			time = v[i].first;
		}
	}
	cout << ans << endl;

    return 0;
}
