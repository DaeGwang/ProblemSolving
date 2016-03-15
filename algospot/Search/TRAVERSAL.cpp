#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

vector<int> slice(const vector<int>& v, int a, int b){
	return vector<int>(v.begin()+a, v.begin()+b);
}
void printPostOrder(const vector<int>& preorder, const vector<int>& inorder){
	const int N = preorder.size();
	if(preorder.empty()) return;
	const int root = preorder[0];
	const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
	//const int R = N - 1 - L;
	printPostOrder(slice(preorder, 1, L+1), slice(inorder, 0, L));
	printPostOrder(slice(preorder, L+1, N), slice(inorder, L+1, N));
	cout << root << ' ';
}
int main()
{
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	int n;
	int a, b;
	vector<int> pre;
	vector<int> in;
	while(T--){
		pre.clear();
		in.clear();
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> a;
			pre.push_back(a);
		}
		for(int i=0; i<n; i++){
			cin >> b;
			in.push_back(b);
		}
		printPostOrder(pre, in);
		cout << endl;
	}
	return 0;
}

