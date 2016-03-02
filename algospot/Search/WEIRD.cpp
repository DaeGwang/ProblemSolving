#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <functional> //greater
using namespace std;
int n;

vector<int> getDivisors(int n){
	vector<int> v;
	v.push_back(1);
	for(int i=2; i<=n/2; i++){
		if(n % i == 0){
			v.push_back(i);
		}
	}
	//sort(v.begin(), v.end(), greater<int>);
	return v;
}
int getSum(vector<int>& v){
	int sum = 0;
	for(int i=0; i<v.size(); i++){
		sum += v[i];
	}
	return sum;
}
bool exist(vector<int>& v, int sum, int n, int index){
	if(sum < n || n < 0) return false;
	if(sum==n) return true;
	int now = v[index];
	if(exist(v, sum-now, n-now, index-1)) return true;
	return (exist(v, sum-now, n, index-1));
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;

	int sum;
	vector<int> v;
	while(T--){
		cin >> n;
		v = getDivisors(n);
		sum = getSum(v);
		if((sum > n) && !exist(v, sum, n, v.size()-1)){
			cout << "weird" << endl;
		}
		else{
			cout << "not weird" << endl;
		}
	}

	return 0;
}
