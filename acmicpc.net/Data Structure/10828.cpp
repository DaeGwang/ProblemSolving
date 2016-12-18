#include<stdio.h>
#include<cstring>
using namespace std;

int s = 0;
int stack[10005];

void push(int a){
	stack[s++] = a;
}
int empty(){
	return s>0 ? 0 : 1;
}
int size(){
	return s;
}
int pop(){
	if(empty()) return -1;
	else return stack[--s];
}
int top(){
	if(empty()) return -1;
	else return stack[s-1];
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    char s[1001];
    for(int i=0; i<n; i++){
    	scanf("%s", s);
    	if(strcmp(s,"push")==0){
    		int a;
    		scanf("%d", &a);
    		push(a);
    	}
    	if(strcmp(s,"pop")==0){
    		printf("%d\n", pop());
    	}
    	if(strcmp(s,"size")==0){
    		printf("%d\n", size());
    	}
    	if(strcmp(s,"empty")==0){
			printf("%d\n", empty());
		}
    	if(strcmp(s,"top")==0){
			printf("%d\n", top());
		}
    }
	return 0;
}
