#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(){
    //freopen("input.txt", "r", stdin);
	int n;
	vector<pair<int, int> > v;
	int a, b;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());
	for(int i=1; i<(int)v.size(); i++){
		if(v[i].second < v[i-1].second){
			cout << "Happy Alex" << endl;
			return 0;
		}
	}
	cout << "Poor Alex" << endl;
    return 0;
}

