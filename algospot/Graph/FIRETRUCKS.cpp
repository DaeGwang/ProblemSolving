#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

#define INF 100000;
int main(){
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    vector<int> target;
	vector<pair<int, int> > ad[1001];
    while(T--){
		int v, e, n, m;
		scanf("%d %d %d %d", &v, &e, &n, &m);
		target.clear();
		int from, to, weight;
		int dis[1001];
		for(int i=0; i<=v; i++){
			ad[i].clear();
		}
		for(int i=0; i<e; i++){
			scanf("%d %d %d", &from, &to, &weight);
			ad[from].push_back(make_pair(to, weight));
			ad[to].push_back(make_pair(from, weight));
		}
		for(int i=0; i<n; i++){
			scanf("%d", &to);
			target.push_back(to);
		}

		for(int i=0; i<=v; i++){
			dis[i] = INF;
		}
		for(int i=0; i<m; i++){
			scanf("%d", &to);
			ad[0].push_back(make_pair(to, 0));
			dis[to] = 0;
		}
		vector<bool> visited(v+1, false);
		dis[0] = 0;
		visited[0] = true;
		while(true){
			int closest = INF;
			int here;
			for(int i=0; i<=v; i++){
				if(dis[i] < closest && !visited[i]){
					here = i;
					closest = dis[i];
				}
			}
			if(closest == 100000){
				break;
			}
			visited[here] = true;
			for(int i=0; i<(int)ad[here].size(); i++){
				int there = ad[here][i].first;
				if(visited[there]) continue;
				int nextDist = dis[here] + ad[here][i].second;
				dis[there] = min(dis[there], nextDist);
			}
		}
		int sum = 0;
		for(int i=0; i<n; i++){
			sum += dis[target[i]];
		}
		printf("%d\n", sum);
    }
    return 0;
}

