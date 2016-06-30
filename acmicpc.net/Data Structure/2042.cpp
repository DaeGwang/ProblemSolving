#include <cstdio>
#include <vector>

using namespace std;

struct SegmentTree{
	vector<long long> tree;
	vector<long long> a;

	SegmentTree(vector<long long> &_a){
		a = _a;
		int n = a.size();
		tree.resize(n*4);
		init(1, 0, n-1);
	}

	long long init(int node, int left, int right){
		int mid = (left + right) / 2;
		if(left == right) return tree[node] = a[left];
		return tree[node] = init(node * 2, left, mid) + init(node * 2 + 1, mid + 1, right);
	}

	long long sum(int node, int left, int right, int x, int y){
		if(x > right || left > y) return 0;
		if(x <= left && right <= y) return tree[node];
		int mid = (left + right) / 2;
		return sum(node * 2, left, mid, x, y) +
			   sum(node * 2 + 1, mid + 1, right, x, y);
	}

	long long sum(int x, int y){
		return sum(1, 0, a.size() - 1, x, y);
	}

	void update(int node, int left, int right, int index, long long num){
		if(index < left || index > right) return;
		long long diff = num - a[index];
		tree[node] = tree[node] + diff;
		int mid = (left + right)/2;
		if(left != right){
			update(node*2, left, mid, index, num);
			update(node*2+1, mid+1, right, index, num);
		}
		else{
			a[index] = num;
		}
	}

	void update(int index, long long num){
		update(1, 0, a.size() - 1, index, num);
	}

};

int main(){
	freopen("input.txt", "r", stdin);
	int M, N, K;
	int a;

	scanf("%d %d %d", &N, &M, &K);
	vector<long long> v(N);

	for(int i=0; i<N; i++){
		scanf("%lld", &v[i]);
	}

	SegmentTree seg(v);

	for(int i=0; i<M+K; i++){
		scanf("%d", &a);
		if(a == 1){
			//update
			int b;
			long long c;
			scanf("%d %lld", &b, &c);
			seg.update(b-1, c);
		}
		if(a == 2){
			//sum
			int b, c;
			scanf("%d %d", &b, &c);
			printf("%lld\n", seg.sum(b-1, c-1));
		}
	}

	return 0;
}