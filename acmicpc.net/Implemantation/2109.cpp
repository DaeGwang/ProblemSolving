#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
int n, d;

int main()
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    vector<pair<int, int> > v(n);
    for(int i=0; i<n; i++) scanf("%d %d", &v[i].second, &v[i].first);
    priority_queue<pair<int, int> > pq;
    int ans = 0;
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
    	pq.push(make_pair(-v[i].second, v[i].first));
    	ans += v[i].second;
    	while(v[i].first < (int)pq.size()) ans+=pq.top().first, pq.pop();
    }
    printf("%d", ans);
    return 0;
}
