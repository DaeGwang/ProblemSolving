#include <stdio.h>
#include <vector>
using namespace std;
const int MAXN = 100005;
vector<int> v[MAXN];
int used[MAXN];
int parent[MAXN];

void dfs(int now){
	used[now] = 1;
	for(int i=0; i<(int)v[now].size(); i++){
		if(used[v[now][i]]==0){
			dfs(v[now][i]);
			parent[v[now][i]] = now;
		}
	}
}


int main()
{
    freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	int from, to;
	for(int i=0; i<n; i++){
		scanf("%d %d", &from, &to);
		v[from].push_back(to);
		v[to].push_back(from);
	}
	dfs(1);
	for(int i=2; i<=n; i++){
		printf("%d\n", parent[i]);
	}
    return 0;
}
