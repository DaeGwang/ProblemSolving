#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct unionFind{
	vector<int> parent, rank, enemy, size;
	unionFind(int n): parent(n), rank(n, 1), enemy(n, -1), size(n, 1) {
		for(int i=0; i<n; i++) parent[i] = i;
	}
	int find(int u){
		if(u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}
	int merge(int u, int v){
		if(u==-1 || v==-1) return max(u, v);
		u=find(u);
		v=find(v);
		if(u==v) return u;
		if(rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		size[v] += size[u];
		if(rank[u] == rank[v]) rank[v]++;
		return v;
	}
	bool dis(int u, int v){
		u = find(u);
		v = find(v);
		if(u == v) return false;
		int a = merge(u, enemy[v]);
		int b = merge(v, enemy[u]);
		enemy[a] = b;
		enemy[b] = a;
		return true;
	}
	bool ack(int u, int v){
		u = find(u);
		v = find(v);
		if(enemy[u] == v) return false;
		int a = merge(u, v);
		int b = merge(enemy[u], enemy[v]);
		enemy[a] = b;
		if(b!=-1) enemy[b] = a;
		return true;
	}
};

int main(){
    freopen("input.txt", "r", stdin);
    int T;
    int m, n;
    cin >> T;
    while(T--){
		cin >> n >> m;
		unionFind buf(n);
		string s;
		int a, b;
		int ans;
		bool con = false;
		for(int i=1; i<=m; i++){
			cin >> s >> a >> b;
			if(con) continue;
			if(s=="ACK"){
				if(!buf.ack(a, b)) con = true;
			}
			else{
				if(!buf.dis(a, b)) con = true;
			}
			if(con) ans=i;
		}
		if(con){
			cout << "CONTRADICTION AT " << ans << endl;
		}
		else{
			int ret = 0;
			for(int node = 0; node < n; node++){
				if(buf.find(node) == node){
					int enemy = buf.enemy[node];
					if(enemy > node) continue;
					int mySize = buf.size[node];
					int enemySize = (enemy == -1 ? 0 : buf.size[enemy]);
					ret += max(mySize, enemySize);
				}
			}
			cout << "MAX PARTY SIZE IS " << ret << endl;
		}
    }
    return 0;
}

