#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

constexpr int MM = 4e5;
int n, m;
std::vector<int> adj[MM];

struct segtree{
#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)
    
    void build(int l = 0, int r = n-1, int rt = 1){
        int nl = l, nr = r;
        if(l == r){
            adj[l].emplace_back(n+rt);
            return;
        }
        adj[n+lc].emplace_back(n+rt);
        adj[n+rc].emplace_back(n+rt);
        build(l, nm, lc);
        build(nm+1, r, rc);
    }
    
    void update(int l, int r, int val, int nl = 0, int nr = n-1, int rt = 1){
        if(r < nl || l > nr)
            return;
        if(l <= nl && r >= nr){
            adj[n+rt].emplace_back(val);
            return;
        }
        update(l, r, val, nl, nm, lc);
        update(l, r, val, nm+1, nr, rc);
    }
#undef lc
#undef rc
#undef nm
} ST;

int dfn[MM], low[MM], t, path[MM], id[MM], ptr;
bool ins[MM];
void tarjan(int cur){
    
    ins[cur] = 1;
    path[++ptr] = cur;
    dfn[cur] = low[cur] = ++t;
    
    for(const int &u: adj[cur]){
        if(!dfn[u]){
            tarjan(u);
            if(low[u] < low[cur])
                low[cur] = low[u];
        }
        else if(ins[u])
            if(dfn[u] < low[cur])
                low[cur] = dfn[u];
    }
    
    if(dfn[cur] == low[cur]){
        int u = -1;
        while(u != cur){
            u = path[ptr--];
            id[u] = cur;
            ins[u] = 0;
        }
    }
}

std::vector<int> adj2[MM];
int dp[MM];
bool vis[MM];

void dfs(int cur){
    vis[cur] = 1;
    int mx = 0;
    
    for(const int &u: adj2[cur]){
        if(!vis[u]){
            vis[u] = 1;
            dfs(u);
        }
        if(dp[u] > mx)
            mx = dp[u];
    }
    dp[cur] += mx;
}

int main(){
    scan(n, m);
    for(int i = 0,h,l,r; i < m; i++){
        scan(h, l, r);
        ST.update(l-1, r-1, h-1);
    }
    
    ST.build();
    
    tarjan(0);
    
    for(int i = 0; i < MM; i++){
        for(int u: adj[i]){
            if(id[i] != id[u])
                adj2[id[i]].emplace_back(id[u]);
        }
    }
    
    for(int i = 0; i < n; i++){
        if(dfn[i])
            dp[id[i]]++;
        //only add if visited in tarjan's
        //otherwise can not be reached
    }
    
    dfs(id[0]);
    print(dp[id[0]]);
    
    return 0;
}