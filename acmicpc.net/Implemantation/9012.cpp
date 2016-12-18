#include<stdio.h>
#include<cstring>
using namespace std;

char s[101];

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
    	scanf("%s", s);
    	int len = strlen(s);
    	int now = 0;
    	bool ans = true;
    	for(int k=0; k<len; k++){
    		if(s[k]=='('){
    			now++;
    		}
    		if(s[k]==')'){
    		    now--;
			}
    		if(now<0) ans = false;
    	}
    	if(now!=0) ans = false;
    	if(ans) printf("YES\n");
    	else printf("NO\n");
    }

	return 0;
}
