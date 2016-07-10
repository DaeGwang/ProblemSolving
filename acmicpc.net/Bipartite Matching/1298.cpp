#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
const int MAXN = 1000;
int bmatch[MAXN+5];
int visited[MAXN+5];
vector<int> G[MAXN+5];

bool dfs(int here){
	if(visited[here]) return false;
	visited[here] = 1;
	for(int i=0; i<(int)G[here].size(); i++){
		int there = G[here][i];
		if(bmatch[there] == -1 || dfs(bmatch[there])){
			bmatch[there] = here;
			return true;
		}
	}
	return false;
}

int matching() {
	memset(bmatch, -1, sizeof(bmatch));
	int matched=0;
	for(int i=1; i<=n; ++i) {
		memset(visited, 0, sizeof(visited));
		if(dfs(i)) ++matched;
	}
	return matched;
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    int from, to;
    for(int i=0; i<m; i++){
    	cin >> from >> to;
    	G[from].push_back(to);
    }
    cout << matching() << endl;
    return 0;
}
