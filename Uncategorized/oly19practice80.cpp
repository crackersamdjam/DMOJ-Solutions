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
constexpr int MM = 1e5+1, mod = 1e9+7;

int n, k, sz[MM];
ll dp[MM][101][4], tmp[4];
//take at least one child of this 0/1
//take this 0/2
std::vector<int> adj[MM];

void addmod(ll &a, ll b){ a += b; if(a >= mod) a -= mod;}
void submod(ll &a, ll b){ a -= b; if(a < 0) a += mod;}

void dfs(int cur, int pre){
    dp[cur][0][0] = 1;
    dp[cur][1][2] = 1;
    sz[cur] = 1;
    
    for(int u: adj[cur]){
        if(u == pre)
            continue;
        dfs(u, cur);
        sz[cur] += sz[u];
        for(int i = std::min(sz[cur], k); i >= 0; i--){
            
            for(int j = std::min(sz[u], i); j >= 0; j--){
                addmod(tmp[0], dp[u][j][1]*dp[cur][i-j][0] % mod);
                addmod(tmp[1], ((dp[u][j][3])*(dp[cur][i-j][0] + dp[cur][i-j][1]) + dp[u][j][1] * dp[cur][i-j][1]) % mod);
                addmod(tmp[2], (dp[u][j][0] + dp[u][j][1]) * dp[cur][i-j][2] % mod);
                addmod(tmp[3], ((dp[u][j][2] + dp[u][j][3]) * (dp[cur][i-j][2] + dp[cur][i-j][3]) + (dp[u][j][0] + dp[u][j][1]) * dp[cur][i-j][3]) % mod);
            }
            
            for(int j = 0; j < 4; j++){
                dp[cur][i][j] = tmp[j];
                tmp[j] = 0;
            }
        }
    }
}

int cheese;

int main(){
    
    scan(n, k);
    
    for(int i = 0,a,b; i < n-1; i++){
        scan(a, b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    
    for(int i = 1; i <= n; i++)
        cheese = std::max(cheese, (int)adj[i].size());
    if(cheese < 3){
        if(n == k)
            puts("1");
        else if(n == k-1)
            puts("2");
        else
            puts("0");
        return 0;
    }
    
    dfs(1, 0);
    
    ll ans = dp[1][k][1] + dp[1][k][3];
    //must take a child to cover root
    if(ans >= mod)
        ans -= mod;
    
    
    print(ans);
    
    return 0;
}