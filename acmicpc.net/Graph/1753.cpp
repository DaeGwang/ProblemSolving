#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int n, e;
const int INF = 1000000;

int main() {
	freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &e);
	int startPoint;
	scanf("%d", &startPoint);
	vector<vector<pair<int, int> > > v(n+1);
	vector<int> distance(n+1);
	vector<bool> visited(n+1);
	int from, to, value;
	for(int i=0; i<e; i++){
		scanf("%d %d %d", &from, &to, &value);
		v[from].push_back(make_pair(to, value));
	}
	for(int i=1; i<=n; i++) distance[i] = INF;
	distance[startPoint] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, startPoint));

	while(!pq.empty()){
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if(visited[now]) continue;
		visited[now] = true;
		for(int i=0; i<v[now].size(); i++){
			if(distance[v[now][i].first] > cost + v[now][i].second){
				distance[v[now][i].first] = cost + v[now][i].second;
				pq.push(make_pair(-distance[v[now][i].first], v[now][i].first));
			}
		}
	}
	for(int i=1; i<=n; i++){
		if(distance[i]==INF) printf("INF\n");
		else printf("%d\n", distance[i]);
	}
	return 0;
}
