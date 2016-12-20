#include<stdio.h>
#include<cstring>
using namespace std;

const int M = 100000+5;

char s[M];

int main()
{
    freopen("input.txt", "r", stdin);
    scanf("%s", s);
    int a = 0;
    int ans = 0;
    int len = strlen(s);
    for(int i=0; i<len; i++){
    	if(s[i]=='('){
			if(s[i+1]==')'){
				ans+=a;
				i++;
			}
			else{
				a++;
			}
    	}
    	else{
    		a--;
    		ans+=1;
    	}
    }
    printf("%d\n", ans);
	return 0;
}
