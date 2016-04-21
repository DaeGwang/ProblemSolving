#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool visited[102][102];
int data[102][102];

int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};
int n, m;

int main(){
	freopen("input.txt", "r", stdin);

	memset(data, 0, sizeof(data));
	memset(visited, 0, sizeof(visited));

	scanf("%d %d", &n, &m);
	char s[101];
	for(int i=1; i<=n; i++){
		scanf("%s", s);
		for(int j=1; j<=m; j++){
			data[i][j] = s[j-1]-'0';
		}
	}
	queue<pair<int, int> > q;
	q.push(make_pair(1, 1));
	visited[1][1] = true;
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		int y = now.first;
		int x = now.second;
		if(y==n && x==m) break;
		for(int i=0; i<4; i++){
			if(data[y+dy[i]][x+dx[i]]!=0 && !visited[y+dy[i]][x+dx[i]]){
				q.push(make_pair(y+dy[i], x+dx[i]));
				data[y+dy[i]][x+dx[i]] = data[y][x] + 1;
				visited[y+dy[i]][x+dx[i]] = true;
			}
		}
	}
	printf("%d\n", data[n][m]);
    return 0;
}
