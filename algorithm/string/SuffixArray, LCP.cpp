#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Comparator{
	const vector<int>& group;
	int t;
	Comparator(const vector<int>& _group, int _t): group(_group), t(_t){
		group = _group;
		t = _t;
	}
	bool operator() (int a, int b){
		if(group[a] != group[b]) return group[a] < group[b];
		return group[a+t] < group[b+t];
	}
};

vector<int> makeSA(const string &s) {
	int n = s.size();
	int t = 1;
	vector<int> group(n+1);
	vector<int> sa(n);
	for(int i=0;i<n;i++) group[i] = s[i], sa[i] = i;
	group[n] = -1;
	while(t<n) {
		Comparator cmp(group, t);
		sort(sa, sa+n, cmp);
		t *= 2;
		if(t>=n) break;
		vector<int> newGroup(n+1);
		newGroup[n] = -1;
		newGroup[sa[0]] = 0;
		for(int i=0;i<n-1;i++) newGroup[sa[i]] = newGroup[sa[i-1]] + cmp(sa[i-1], sa[i]);
		group = newGroup;
	}
	return sa;
}

vector<int> makeLCP(const string& s) {
	int n = s.size();
	int i,j,k=0;
	vector<int> sa = makeSA(s);
	vector<int> rank(n+1,0);
	vector<int> lcp(n,0);
	for (i=1;i<=n;i++) rank[sa[i]] = i;
	for (i=1;i<=n;lcp[rank[i++]]=k){
		for (k?k--:0,j=sa[rank[i]-1];s[i+k]==s[j+k];k++);
	}
	return lcp;
}


int main(){
	freopen("input.txt", "r", stdin);
    return 0;
}
