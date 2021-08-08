#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4,popcnt,abm,mmx,tune=native")

#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using ll = long long;
const int MM = 1e5+1, LOG = 17;

#define min(x, y) ((x) < (y) ? (x) : (y))

int n, m, dep[MM], lca[LOG][MM];
ll dis[MM];
std::vector<std::pair<int, int>> adj[MM];

int getlca(int u, int v){
    if(dep[u] < dep[v])
        std::swap(u, v);
    for(int i = LOG-1; i >= 0; i--){
        if(~lca[i][u] and dep[lca[i][u]] >= dep[v])
            u = lca[i][u];
    }
    if(u == v)
        return u;
    for(int i = LOG-1; i >= 0; i--){
        if(~lca[i][u] and ~lca[i][v] and lca[i][u] != lca[i][v]){
            u = lca[i][u];
            v = lca[i][v];
        }
    }
    return lca[0][u];
}

ll dist(int a, int b){
    return dis[a]+dis[b]-2*dis[getlca(a, b)];
}

void dfs(int cur, int pre){
    dep[cur] = dep[pre]+1;
    lca[0][cur] = pre;
    for(auto e: adj[cur])
        if(e.first != pre){
            dis[e.first] = dis[cur] + e.second;
            dfs(e.first, cur);
        }
}

int a, b, c, d;
ll da, db, dc, dd;

int main(){
    
    memset(lca, -1, sizeof lca);
    
    scan(n, m);
    for(int i = 0; i < n-1; i++){
        scan(a, b, c);
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    
    dfs(1, 0);
    
    for(int i = 1; i < LOG; i++)
        for(int j = 1; j <= n; j++)
            if(~lca[i-1][j])
                lca[i][j] = lca[i-1][lca[i-1][j]];
            
    a = b = 0;
    for(int i = 0; i < m; i++){
        scan(c, d);
        dc = min(da + dist(a, d) + dist(d, c), db + dist(b, d) + dist(d, c));
        dd = min(da + dist(a, c) + dist(c, d), db + dist(b, c) + dist(c, d));
        a = c, b = d, da = dc, db = dd;
    }
    
    print(min(dc, dd));
            
    return 0;
}