#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(){
    //freopen("input.txt", "r", stdin);
    int d[16] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
    int n = 0;
    bool isComposite = false;
    for(int i=0; i<=15; i++){
    	printf("%d\n", d[i]);
    	fflush(stdout);
    	string s;
    	cin >> s;
    	if(s == "yes"){
    		if(n!=0 && d[i]*n<=100){
    			printf("%d\n", d[i]*n);
    			fflush(stdout);
    			cin >> s;
    			if(s=="yes"){
    				isComposite = true;
    				break;
    			}
    		}
    		if(d[i] * d[i] <= 100){
				printf("%d\n", d[i]*d[i]);
				fflush(stdout);
				cin >> s;
				if(s=="yes"){
					isComposite = true;
					break;
				}
			}
    		n = d[i];
    	}
    }
    if(isComposite) printf("composite\n");
    else printf("prime\n");
	fflush(stdout);
    return 0;
}
