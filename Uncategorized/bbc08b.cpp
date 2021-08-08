#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 1e5+5, LOG = 17, MN = 1e6+5;
const ll mod = 1e9+7;

int n, k, dep[MM], sp[LOG][MM];
ll ans, val[MN], up[MM], down[MM];
vector<pair<int, int>> adj[MM];

int getlca(int u, int v){
    if(dep[u] < dep[v])
        swap(u, v);
    for(int i = LOG-1; i >= 0; i--){
        if(~sp[i][u] and dep[sp[i][u]] >= dep[v])
            u = sp[i][u];
    }
    if(u == v)
        return u;
    for(int i = LOG-1; i >= 0; i--){
        if(~sp[i][u] and ~sp[i][v] and sp[i][u] != sp[i][v]){
            u = sp[i][u];
            v = sp[i][v];
        }
    }
    return sp[0][u];
}

void dfs(int cur, int pre){
    dep[cur] = dep[pre]+1;
    sp[0][cur] = pre;
    for(auto e: adj[cur]){
        if(e.first != pre)
            dfs(e.first, cur);
    }
}

void go(int cur, int pre, int t){
    for(auto e: adj[cur]){
        if(e.first == pre)
            continue;
        
        go(e.first, cur, e.second);
        up[cur] += up[e.first];
        down[cur] += down[e.first];
    }
    
    if(t == 1){
        ans += val[up[cur]]-1;
        ans %= mod;
    }
    if(t == 2){
        ans += val[down[cur]]-1;
        ans %= mod;
    }
}

int main(){
    memset(sp, -1, sizeof sp);
    
    val[0] = 1;
    for(int i = 1; i < MN; i++)
        val[i] = val[i-1]*2%mod;
    
    scan(n);
    for(int i = 0,a,b,c; i < n-1; i++){
        scan(a, b, c);
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c+c);
    }
    
    dfs(1, 0);
    
    for(int i = 1; i < LOG; i++){
        for(int j = 1; j <= n; j++){
            if(~sp[i-1][j])
                sp[i][j] = sp[i-1][sp[i-1][j]];
        }
    }
    
    scan(k);
    int a = 1, b;
    while(k--){
        scan(b);
        int l = getlca(a, b);
        up[a]++;
        up[l]--;
        down[b]++;
        down[l]--;
        
        a = b;
    }
    
    go(1, 0, 0);
    
    print(ans);
    
    return 0;
}