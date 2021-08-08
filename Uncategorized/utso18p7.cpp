#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
typedef long long ll;
const int MM = 1e5+2, mod = 1e9+7;

int N, M, sz[MM], tot;
ll ans[MM], c[MM], rm[MM];
bool vis[MM];
vector<int> adj[MM];
vector<pair<int, ll>> up[MM];

int getsz(int cur, int pre){
    sz[cur] = 1;
    for(int u: adj[cur]){
        if(u != pre && !vis[u])
            sz[cur] += getsz(u, cur);
    }
    return sz[cur];
}

int findcent(int cur, int pre){
    for(int u: adj[cur]){
        if(!vis[u] && u != pre && sz[u]*2 > tot)
            return findcent(u, cur);
    }
    return cur;
}

void dfs(int cur, int pre, int cent, ll val){
    up[cur].push_back({cent, val});
    for(int u: adj[cur]){
        if(!vis[u] && u != pre)
            dfs(u, cur, cent, val*c[cur]%mod);
    }
}

void go(int rt){
    
    getsz(rt, -1);
    tot = sz[rt];
    
    if(tot == 1)
        return;
    
    int cent = findcent(rt, -1);
    vis[cent] = 1;
    
    for(int u: adj[cent])
        if(!vis[u])
            dfs(u, cent, cent, 1);
    
    for(int u: adj[cent])
        if(!vis[u])
            go(u);
}

int main(){
    
    scan(N, M);
    
    for(int i = 1; i <= N; i++)
        scan(c[i]);
    
    for(int i = 0,a,b; i < N-1; i++){
        scan(a, b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i = 1; i <= N; i++){
        if(adj[i].size() == 1){
            go(i);
            break;
        }
    }
    
    for(int i = 1; i <= N; i++)
        reverse(up[i].begin(), up[i].end());
    
    for(int t = 0,op,a,b; t < M; t++){
        scan(op, a);
        if(op == 1){
            scan(b);
            ans[a] = (ans[a] + b) % mod;
            int p = a;
            for(auto cent: up[a]){
                ans[cent.first] += b * cent.second % mod * c[a] % mod;
                ans[cent.first] %= mod;
                rm[p] += b * cent.second % mod * c[a] % mod;
                rm[p] %= mod;
                p = cent.first;
            }
        }
        else{
            ll ret = ans[a];
            int p = a;
            for(auto cent: up[a]){
                ret += (cent.second * c[cent.first] % mod) * (((ans[cent.first] - rm[p]) % mod + mod) % mod) % mod;
                ret %= mod;
                p = cent.first;
            }
            print(ret);
        }
    }
    
    return 0;
}