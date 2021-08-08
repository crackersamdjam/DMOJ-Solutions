//danyang
#include <bits/stdc++.h>
using namespace std;
#define MM 100002
int par[MM],N,Q,x,y;
char q;
inline void init(){
    for(int i = 1; i <= N; i++)
        par[i] = i;
}
int find(int x){
    while(x != par[x]){
        x = par[x];
        par[x] = par[par[x]];
    }return x;
}
void merge(int x, int y){
    par[find(x)] = find(y);
}
int main(){
    scanf("%d%d",&N,&Q);
    init();
    while(Q--){
        scanf("\n%c%d%d",&q,&x,&y);
        switch(q){
            case 'A':
                merge(x, y);
                break;
            case 'Q':
                printf((find(x) == find(y)) ? "Y\n": "N\n");
                break;
        }
    }
    return 0;
}