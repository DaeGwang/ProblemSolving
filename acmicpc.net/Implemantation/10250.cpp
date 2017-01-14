#include <stdio.h>

int main(){
    freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    int w, h, key, ans;
    while(t--){
    	scanf("%d %d %d", &h, &w, &key);
    	ans = (key%h==0 ? (h*100+key/h) : ((key%h)*100+(key/h)+1));
    	printf("%d\n", ans);
    }
    return 0;
}
