#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
char word[100];
bool visited[10];
bool flag = false;

void maxFind(int m, string s){
    if(flag) return;
    if(m==n){
        cout << s << endl;
        flag = true;
        return;
    }
    char lastChar = s[s.length()-1];
    for(int i=9; i>=0; i--){
        if(!visited[i]){
            if(word[m]=='<'){
                if(lastChar < i+'0'){
                    visited[i] = true;
                    string ns = s + (char)(i+'0');
                    maxFind(m+1, ns);
                    visited[i] = false;
                }
            }
            else{
                if(lastChar > i+'0'){
                    visited[i] = true;
                    string ns = s + (char)(i+'0');
                    maxFind(m+1, ns);
                    visited[i] = false;
                }
            }
        }
    }
}

void minFind(int m, string s){
    if(flag) return;
    if(m==n){
        cout << s << endl;
        flag = true;
        return;
    }
    char lastChar = s[s.length()-1];
    for(int i=0; i<10; i++){
        if(!visited[i]){
            if(word[m]=='<'){
                if(lastChar < i+'0'){
                    visited[i] = true;
                    string ns = s + (char)(i+'0');
                    minFind(m+1, ns);
                    visited[i] = false;
                }
            }
            else{
                if(lastChar > i+'0'){
                    visited[i] = true;
                    string ns = s + (char)(i+'0');
                    minFind(m+1, ns);
                    visited[i] = false;
                }
            }
        }
    }
}
int main(){
    freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    cin >> word;
    //for(int i=0; i<=n; i++) cin >> word[i];
    for(int i=0; i<=n; i++) cout << word[i] << endl;
    flag = false;
    memset(visited, 0, sizeof(visited));
    for(int i=9; i>=0; i--){
        visited[i] = true;
        string s = "";
        s+=(char)(i+'0');
        maxFind(0, s);
        visited[i] = false;
    }
    flag = false;
    memset(visited, 0, sizeof(visited));
    for(int i=0; i<10; i++){
        visited[i] = true;
        string s = "";
        s+=(char)(i+'0');
        minFind(0, s);
        visited[i] = false;
    }

    return 0;
}