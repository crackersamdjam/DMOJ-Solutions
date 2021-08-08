#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using T = int;
using ll = long long;
const int MM = (5e5+5)*5;

ll sum, mod = 1e9+7;
int n;
vector<int> adj[MM];

struct segtree{
#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)
    T DEF = 0;
    
    void build(int l = 0, int r = n-1, int rt = 1){
        int nl = l, nr = r;
        
        if(l == r){
            adj[n+rt].emplace_back(l);
            return;
        }
        adj[n+rt].emplace_back(n+lc);
        adj[n+rt].emplace_back(n+rc);
        build(l, nm, lc);
        build(nm+1, r, rc);
    }
    
    void update(int l, int r, T val, int nl = 0, int nr = n-1, int rt = 1){
        if(r < nl || l > nr)
            return;
        if(l <= nl && r >= nr){
            adj[val].emplace_back(n+rt);
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
    
    for(int u: adj[cur]){
        if(!dfn[u]){
            tarjan(u);
            low[cur] = min(low[cur], low[u]);
        }
        else if(ins[u])
            low[cur] = min(low[cur], dfn[u]);
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

pair<ll, ll> a[MM];
#define x first
#define r second

set<int> adj2[MM];
ll dp[MM];
bool vis[MM];

ll dfs(int cur){
    if(vis[cur])
        return dp[cur];
    vis[cur] = 1;
    for(int u: adj2[cur])
        dp[cur] += dfs(u);
    return dp[cur];
}

int main(){
    scan(n);
    for(int i = 0; i < n; i++){
        scan(a[i].x, a[i].r);
    }
    sort(a, a+n);
    for(int i = 0; i < n; i++){
        int l = lower_bound(a, a+n, make_pair(a[i].x-a[i].r, 0LL))-a;
        int r = upper_bound(a, a+n, make_pair(a[i].x+a[i].r, LLONG_MAX))-1-a;
        ST.update(l, r, i);
    }
    
    ST.build();
    
    for(int i = 0; i < MM; i++){
        if(!dfn[i])
            tarjan(i);
    }
    
    for(int i = 0; i < MM; i++){
        for(int u: adj[i]){
            if(id[i] != id[u]){
                adj2[id[i]].insert(id[u]);
            }
        }
    }
    
    for(int i = 0; i < n; i++)
        dp[id[i]]++;
    
    for(int i = 0; i < n; i++)
        sum = (sum + (i+1)*dfs(id[i])) % mod;
    
    print(sum);
    
    return 0;
}