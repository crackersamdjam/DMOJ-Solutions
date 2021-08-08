#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define MM 50002
#define MN 16
#define f first
#define s second
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef pair<int, int> pii;
int N,M, par[MM], dep[MM], lca[MN][MM], cost[MN][MM], sum, E;
vector<pii> adj[MM];
struct edge{
    int a,b,c,d;
    friend bool operator<(const edge &x, const edge &y){
        return x.c < y.c;
    }
} edges[MM<<1];
inline int find(int x){
    while(x != par[x]){
        x = par[x];
        par[x] = par[par[x]];
    }
    return x;
}
inline bool merge(int a, int b){
    int fa = find(a), fb = find(b);
    if(fa != fb){
        par[fa] = fb;
        return 1;
    }
    return 0;
}
inline void kruskal(){
    for(int i = 1; i <= N; i++)
        par[i] = i;
    sort(edges, edges+M);
    for(int i = 0; i < M; i++){
        edge &e = edges[i];
        if(merge(e.a, e.b)){
            e.d = 1; //part of mst
            adj[e.a].push_back({e.b, e.c});
            adj[e.b].push_back({e.a, e.c});
            sum += e.c;
            if(++E == N-1)
                break;
        }
    }
}
void dfs(int cur, int pre){
    for(auto &u: adj[cur]){
        if(u.f != pre){
            dep[u.f] = dep[cur] + 1;
            lca[0][u.f] = cur;
            cost[0][u.f] = u.s;
            dfs(u.f, cur);
        }
    }
}
inline void buildLca(){
    for(int i = 1; i < MN; i++){
        for(int j = 1; j <= N; j++){
            if(lca[i-1][j] != -1){
                lca[i][j] = lca[i-1][lca[i-1][j]];
                cost[i][j] = max(cost[i-1][j], cost[i-1][lca[i-1][j]]);
            }
        }
    }
}
//return lca
inline int queryLca(int u, int v){
    if(dep[u] < dep[v])
        swap(u, v);
    for(int i = MN-1; i >= 0; i--){
        if((lca[i][u] != -1) && (dep[lca[i][u]] >= dep[v]))
            u = lca[i][u];
    }
    if(u == v)
        return u;
    for(int i = MN-1; i >= 0; i--){
        if((lca[i][u] != -1) && (lca[i][v] != -1) && (lca[i][u] != lca[i][v])){
            u = lca[i][u];
            v = lca[i][v];
        }
    }
    return lca[0][u];
}
//return maximum weight edge from a-b
inline int query(int a, int b){
    
    int lcan = queryLca(a, b), ret = 0;
    
    for(int i = MN-1; i >= 0; i--){
        if(dep[a] >= dep[lcan] + (1<<i)){
            ret = max(ret, cost[i][a]);
            a = lca[i][a];
        }
    }
    
    for(int i = MN-1; i >= 0; i--){
        if(dep[b] >= dep[lcan] + (1<<i)){
            ret = max(ret, cost[i][b]);
            b = lca[i][b];
        }
    }
    return ret;
}
int main(){
    sc(N); sc(M);
    for(int i = 0,a,b,c; i < M; i++){
        sc(a); sc(b); sc(c);
        edges[i] = {a,b,c,0};
    }
    kruskal();
    if(E != N-1){
        printf("-1\n");
        return 0;
    }
    
    memset(lca,-1,sizeof(lca));
    memset(cost,-1,sizeof(cost));
    dfs(1, 0);
    buildLca();
    
    int ans = INT_MAX;
    for(int i = 0; i < M; i++){
        edge &e = edges[i];
        if(!e.d){
            int dif = sum + e.c - query(e.a, e.b);
            if(dif != sum && dif < ans)
                ans = dif;
        }
    }
    printf("%d\n", (ans == INT_MAX ? -1: ans));
    return 0;
}