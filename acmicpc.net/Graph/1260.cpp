#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m, v;
int d[1005][1005];
int visited[1005];

void dfs(int v){
    printf("%d ", v);
    visited[v] = 1;
    for(int i=0; i<=n; i++){
        if(d[v][i]==1 && (visited[i] != 1)) dfs(i);
    }
}

void bfs(int v){
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int s = q.front();
        q.pop();
        if(visited[s] != 1) printf("%d ", s);
        visited[s] = 1;
        for(int i=0; i<=n; i++){
            if(d[s][i]==1 && (visited[i] != 1)) q.push(i);
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);


    scanf("%d %d %d", &n, &m, &v);
    int start, end;
    memset(d, 0, sizeof(d));
    memset(visited, 0, sizeof(visited));
    for(int i=0; i<m; i++){
        scanf("%d %d", &start, &end);
        d[start][end] = 1;
        d[end][start] = 1;
    }
    dfs(v);
    printf("\n");

    memset(visited, 0, sizeof(visited));
    bfs(v);
    printf("\n");
    return 0;
}
