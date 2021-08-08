#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using pii = pair<int, int>;
const int MM = 5e5+5, LOG = 20, MN = 1<<20;

bool dp[MN];
int n, m, V, sp[LOG][MM], val[LOG][MM], dep[MM];
bool vis[MM];
vector<pair<int, int>> adj[MM];
vector<pair<pii, int>> v;

int getlca(int u, int v){
    if(dep[u] < dep[v])
        swap(u, v);
    for(int i = LOG-1; i >= 0; i--){
        if(~sp[i][u] && (dep[sp[i][u]] >= dep[v]))
            u = sp[i][u];
    }
    if(u == v)
        return u;
    for(int i = LOG-1; i >= 0; i--){
        if(~sp[i][u] && ~sp[i][v] && (sp[i][u] != sp[i][v])){
            u = sp[i][u];
            v = sp[i][v];
        }
    }
    return sp[0][u];
}

int query(int a, int b){
    int lcan = getlca(a, b), ret = 0;
    for(int i = LOG-1; i >= 0; i--){
        if(dep[a] >= dep[lcan] + (1<<i)){
            ret ^= val[i][a];
            a = sp[i][a];
        }
    }
    for(int i = LOG-1; i >= 0; i--){
        if(dep[b] >= dep[lcan] + (1<<i)){
            ret ^= val[i][b];
            b = sp[i][b];
        }
    }
    return ret;
}

void dfs(int cur, int pre, int edg){
    vis[cur] = 1;
    dep[cur] = dep[pre]+1;
    sp[0][cur] = pre;
    val[0][cur] = edg;
    for(auto e: adj[cur]){
        if(!vis[e.first]){
            dfs(e.first, cur, e.second);
        }
        else if(e.first != pre){
            v.push_back({{cur, e.first}, e.second});
        }
    }
}

int main(){
    memset(sp, -1, sizeof sp);
    scan(n, m, V);
    for(int i = 0,a,b,c; i < m; i++){
        scan(a, b, c);
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    dfs(1, 0, 0);
    for(int i = 1; i < LOG; i++){
        for(int j = 0; j <= n; j++){
            if(~sp[i-1][j]){
                sp[i][j] = sp[i-1][ sp[i-1][j] ];
                val[i][j] = val[i-1][j] ^ val[i-1][ sp[i-1][j] ];
            }
        }
    }
    dp[0] = 1;
    for(auto e: v){
        int b = query(e.first.first, e.first.second)^e.second;
        if(dp[b])
            continue;
        for(int i = 0; i < MN; i++)
            dp[i^b] |= dp[i];
        if(dp[V])
            return puts("yes"), 0;
    }
    puts("no");
    
    return 0;
}