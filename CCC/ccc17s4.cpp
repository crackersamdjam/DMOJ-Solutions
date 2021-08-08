#include <bits/stdc++.h>
using namespace std;
const int MM = 100001;

int N, M, D, ans, par[MM], maxedge, cnt;

inline int find(int x){
    while(x != par[x]){
        x = par[x];
        par[x] = par[par[x]];
    }
    return x;
}

struct edge{
    int a, b, c, d;
    inline bool merge(){
        int fa = find(a), fb = find(b);
        if(fa != fb){
            par[fa] = fb;
            return 1;
        }
        return 0;
    }
};
vector<edge> edges;

int main(){
    
    scanf("%d%d%d", &N, &M, &D);
    
    for(int i = 0,a,b,c; i < M; i++){
        scanf("%d%d%d", &a, &b, &c);
        edges.push_back({a, b, c, i >= N-1});
    }
    
    sort(edges.begin(), edges.end(), [](const edge &x, const edge &y){
        if(x.c == y.c)
            return x.d < y.d;
        return x.c < y.c;
    });
    
    for(int i = 1; i <= N; i++)
        par[i] = i;
    
    for(edge &e: edges){
        if(e.merge()){
            if(e.d)
                ans++;
            maxedge = e.c;
            
            if(++cnt == N-1)
                break;
        }
    }
    
    if(D){
        for(int i = 1; i <= N; i++)
            par[i] = i;
    
        for(edge &e: edges){
            int fa = find(e.a), fb = find(e.b);
            if(fa != fb){
                if(e.c < maxedge || (e.c == maxedge && !e.d))
                    par[fa] = fb;
                else if(!e.d && e.c <= D){
                    ans--;
                    break;
                }
            }
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}