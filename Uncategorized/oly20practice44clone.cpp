#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#define ll long long
//using namespace std;
//using ll = long long;
constexpr int MM = 1e6+1, LOG = 20;

int n, k, q, in[MM], sz[MM], tot, dis[LOG][MM], dep[MM], par[MM], st[MM], ptr;
std::vector<int> adj[MM];
bool vis[MM];

inline int min(int a, int b){
    return (a<b?a:b);
}
inline int max(int a, int b){
    return (a>b?a:b);
}

int getsz(int cur, int pre){
    sz[cur] = 1;
    for(auto e: adj[cur]){
        if(e != pre && !vis[e])
            sz[cur] += getsz(e, cur);
    }
    return sz[cur];
}

int findcent(int cur, int pre){
    for(auto e: adj[cur]){
        if(!vis[e] && e != pre && sz[e]*2 > tot)
            return findcent(e, cur);
    }
    return cur;
}

int dfs(int cur, int pre, int l){
    sz[cur] = 1;
    for(auto u: adj[cur]){
        if(u == pre || vis[u])
            continue;
        dis[l][u] = dis[l][cur] + 1;
        sz[cur] += dfs(u, cur, l);
    }
    return sz[cur];
}

void go(int root, int pre, int l){
//    assert(l < LOG);

    tot = sz[root];
    
    if(tot == 1){
        dep[root] = l;
        par[root] = pre;
        st[root] = ptr++;
        return;
    }
    
    int cent = findcent(root, -1);
    
    dep[cent] = l;
    vis[cent] = 1;
    par[cent] = pre;
    st[cent] = ptr++;
    
    for(auto u: adj[cent]){
        if(!vis[u]){
            dis[l][u] = 1;
            dfs(u, cent, l);
            go(u, cent, l+1);
        }
    }
}

inline bool cmp(int a, int b){
    return st[a] < st[b];
}

int last[MM], mn[MM], mx[MM];
ll dp[MM];
std::vector<int> add[MM];

int main(){
    scan(n);
    
    for(int i = 0,a,b; i < n-1; i++){
        scan(a, b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    
    getsz(1, -1);
    go(1, -1, 0);
    
    memset(mn, 0x3f, sizeof mn);
    memset(mx, -0x3f, sizeof mx);
    memset(sz, 0, sizeof sz);
    
    scan(q);
    for(int t = 0; t < q; t++){
        scan(k);
        for(int i = 0; i < k; i++){
            scan(in[i]);
        }
        std::sort(in, in+k, cmp);
        
        int allmn = mn[0], allmx = mx[0];
        ll alldp = dp[0];
        
        for(int i = 0; i < k; i++){
            int u = in[i], pre = u;
            while(~u){
                if(last[u] != pre){
                    
                    last[u] = pre;
                    //add last batch
                    for(int j: add[u]){
                        allmn = min(allmn, mn[u] + dis[dep[u]][j]);
                        allmx = max(allmx, mx[u] + dis[dep[u]][j]);
                        alldp += dp[u] + (ll)sz[u]*dis[dep[u]][j];
                    }
                    for(int j: add[u]){
                        mn[u] = min(mn[u], dis[dep[u]][j]);
                        mx[u] = max(mx[u], dis[dep[u]][j]);
                        dp[u] += dis[dep[u]][j];
                        sz[u]++;
                    }
                    add[u].clear();
                }
                add[u].emplace_back(in[i]);
                pre = u;
                u = par[u];
            }
        }
        //last batch and clear
        for(int i = 0; i < k; i++){
            int u = in[i];
            while(~u){
                if(!last[u])
                    break;
                for(int j: add[u]){
                    allmn = min(allmn, mn[u] + dis[dep[u]][j]);
                    allmx = max(allmx, mx[u] + dis[dep[u]][j]);
                    alldp += dp[u] + (ll)sz[u]*dis[dep[u]][j];
                }
                add[u].clear();
                mn[u] = mn[0];
                mx[u] = mx[0];
                dp[u] = dp[0];
                sz[u] = sz[0];
                last[u] = last[0];
                u = par[u];
            }
        }
        
        print(alldp, allmn, allmx);
    }
    
    return 0;
}