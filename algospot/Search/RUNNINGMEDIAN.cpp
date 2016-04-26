#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct CR{
	long long num;
	CR(): num(1983){}
	long long next(int a, int b){
		num = (num * a + b) % 20090711;
		return num;
	}
};

int main(){
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--){
		int n, a, b;
		long long d[200001];
		long long sum = 0;
		scanf("%d", &n);
		scanf("%d %d", &a, &b);
		CR c;
		d[0] = 1983;
		priority_queue<int> qA;
		priority_queue<int, deque<int>, greater<int> > qB;
		qA.push(d[0]);
		sum = d[0];
		for(int i=1; i<n; i++){
			d[i] = c.next(a, b);
			while(qA.size() <= qB.size()){
				qA.push(qB.top());
				qB.pop();
			}
			if(d[i] > qA.top()){
				qB.push(d[i]);
			}
			else{
				qB.push(qA.top());
				qA.pop();
				qA.push(d[i]);
			}
			sum = (sum + qA.top()) % 20090711;
		}
		printf("%lld\n", sum);
    }
    return 0;
}

