#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int n;
int d[100001];

int binary_search(int k, int start, int end)
{
  int mid;
  while(start<=end)
  {
    mid=(start+end)/2;
    if(d[mid]<k)start=mid+1;
    else if(d[mid]>k)end=mid-1;
    else return mid;
  }
  return start;
}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> n;
    for(int i=0; i<n; i++){
        scanf("%d", &d[i]);
    }
    ll sum = 0;
    int ansLeft = 0;
    int ansRight = n-1;
    ll ans = 2000000001;
    for(int i=0; i<n; i++){
    	int t = binary_search(-d[i], i, n-1);
    	for(int k=t-1; k<=t+1; k++){
    		if(k<=i || k>=n) continue;
			sum = abs(d[i]+d[k]);
			if(sum < ans){
				ans = sum;
				ansLeft = i;
				ansRight = k;
			}
    	}
    }
    cout << d[ansLeft] << " " << d[ansRight] << endl;
    return 0;
}
