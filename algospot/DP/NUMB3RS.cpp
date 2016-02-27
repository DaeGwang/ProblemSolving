#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int ad[51][51];
double ans[51];
double ansT[51];
int numbers[51];

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;

	int n, d, p, t;
	while(T--){
		cin >> n;
		cin >> d;
		cin >> p;
		for(int i=0; i<n; i++){
			numbers[i] = 0;
			for(int j=0; j<n; j++){
				cin >> ad[i][j];
				if(ad[i][j]==1) numbers[i]++;
			}
		}
		for(int i=0; i<n; i++) ans[i] = 0;
		for(int i=0; i<n; i++) ansT[i] = 0;
		ans[p] = 1;
		for(int i=0; i<d; i++){
			for(int k=0; k<n; k++){
				ansT[k] = 0;
			}
			for(int j=0; j<n; j++){
				for(int k=0; k<n; k++){
					if(ad[j][k]==1){
						ansT[k] += ans[j] / numbers[j];
					}
				}
			}
			for(int k=0; k<n; k++){
				ans[k] = ansT[k];
			}
		}
		cin >> t;
		int vNum;
		for(int i=0; i<t; i++){
			cin >> vNum;
			printf("%.8f",ans[vNum]);
			if(i==t-1) cout << endl;
			else cout << " ";
		}
	}
}
