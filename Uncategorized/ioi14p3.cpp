#include <bits/stdc++.h>
using namespace std;
const int MM = 1501;

int n, par[MM], cnt[MM][MM];

int find(int x){
    while(x ^ par[x])
        x = par[x], par[x] = par[par[x]];
    return x;
}

void initialize(int m){
    n = m;
    for(int i = 0; i < n; i++){
        par[i] = i;
        for(int j = 0; j < n; j++)
            cnt[i][j] = 1;
    }
}

int hasEdge(int a, int b){
    
    if(a > b)
        swap(a, b);
    
    int fa = find(a), fb = find(b);
    if(fa == fb)
        return 0;
    
    if(fa > fb)
        swap(fa, fb);
    
    if(--cnt[fa][fb] > 0)
        return 0;
    
    par[fb] = fa;
    
    for(int i = 0; i < fa; i++)
        cnt[i][fa] += cnt[i][fb];
    for(int i = fa+1; i < fb; i++)
        cnt[fa][i] += cnt[i][fb];
    for(int i = fb+1; i < n; i++)
        cnt[fa][i] += cnt[fb][i];
    
    return 1;
}

/*
#ifndef ONLINE_JUDGE
int main(){
    
    initialize(4);
    
    print(hasEdge(0, 3));
    print(hasEdge(1, 0));
    print(hasEdge(0, 2));
    print(hasEdge(3, 1));
    print(hasEdge(1, 2));
    print(hasEdge(2, 3));
    
    return 0;
}
#endif
 */