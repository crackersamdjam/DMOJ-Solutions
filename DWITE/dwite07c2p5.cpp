#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#define _CRT_SECURE_NO_WARNINGS
#endif
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
const int MM = 101;

int N, M, tc = 5, dfn[MM], low[MM], t, bridge;
bool vis[MM];
vector<int> adj[MM];


void dfs(int cur, int pre){
    
    vis[cur] = 1;
    dfn[cur] = low[cur] = ++t;
    
    for(const int &u: adj[cur]){
        if(u == pre)
            continue;
        
        if(!vis[u]){
            dfs(u, cur);
            if(low[u] > dfn[cur])
                bridge++;
        }
        low[cur] = min(low[cur], low[u]);
    }
}

int __attribute__((optimize("-O3"))) main(){
    
    while(tc--){
        
        
        for(int i = 1; i < MM; i++)
            adj[i].clear();
        memset(dfn, 0, MM<<2);
        memset(low, 0, MM<<2);
        memset(vis, 0, MM<<2);
        t = bridge = 0;
        
        scan(N, M);
        
        for(int i = 0,a,b; i < M; i++){
            scan(a, b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        dfs(1, -1);
        
        print(bridge);
    }
    
    return 0;
}