#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


int main(){
    freopen("input.txt", "r", stdin);
    int sum;
    scanf("%d", &sum);
    int num;
    for(int i=0; i<9; i++){
    	scanf("%d", &num);
    	sum -= num;
    }
    printf("%d\n", sum);
    return 0;
}

