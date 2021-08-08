#include <bits/stdc++.h>
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
int W, D, d[10], V, v[5];
bool b[7][5000002];
void go(int val, int rem){
    if(val > 5000000 || b[rem][val])
        return;
    b[rem][val] = 1;
    if(rem == 0)
        return;
    for(int i = 0; i < D; i++){
        go(val + d[i], rem-1);
        go(val * d[i], rem-1);
    }
}
int main(){
    sc(W); sc(D);
    for(int i = 0; i < D; i++)
        sc(d[i]);
    sc(V);
    for(int i = 0; i < V; i++)
        sc(v[i]);
    for(int i = 0; i < D; i++)
        go(d[i], W);
    for(int i = 0; i < V; i++){
        putchar_unlocked(b[0][v[i]]? 'Y': 'N');
        putchar_unlocked('\n');
    }
    return 0;
}