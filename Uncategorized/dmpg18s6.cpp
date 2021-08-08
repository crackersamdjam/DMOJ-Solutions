#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}
void print(int x, int y){print(x); pc(32); print(y); pc(10);};

using namespace std;
const int MM = 1e5+1;

int N, M, dfn[MM], low[MM], t, sz[MM], ans = INT_MAX, node = -1;
bool vis[MM];
set<int> adj[MM];

void dfs(int cur, int pre){
    
    bool art = 0;
    int sum = 0, high = 0, child = 0;
    
    sz[cur] = vis[cur] = 1;
    dfn[cur] = low[cur] = ++t;
    
    for(int u: adj[cur]){
        
        if(u != pre){
            if(!vis[u]){
                
                child++;
                
                dfs(u, cur);
                
                sz[cur] += sz[u];
                low[cur] = min(low[cur], low[u]);
                
                if((pre == -1 && child > 1) or (pre != -1 && low[u] >= dfn[cur])){
                    art = 1;
                    high = max(high, sz[u]);
                    sum += sz[u];
                }
            }
            else
                low[cur] = min(low[cur], dfn[u]);
        }
    }
    
    if(art){
        high = max(high, N - sum - 1);
        
        if(high < ans)
            ans = high, node = cur;
        else if(high == ans)
            node = max(node, cur);
    }
}

int main(){
    
    scan(N, M);
    
    for(int i = 0,a,b; i < M; i++){
        scan(a, b);
        adj[a].insert(b);
        adj[b].insert(a);
    }
    
    dfs(1, -1);
    
    if(node == -1)
        puts("-1 -1");
    else
        print(node, ans);
    
    return 0;
}