#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;
constexpr int MM = 2001;

int n, k, sz[MM];
ll dp[MM][1001], temp[MM];
vector<pair<int, int>> adj[MM];

void dfs(int cur, int pre){
    sz[cur] = 1;
    dp[cur][0] = dp[cur][1] = 0;
    
    for(auto e: adj[cur]){
        int u = e.first; ll w = e.second;
        if(u == pre)
            continue;
        
        dfs(u, cur);
        sz[cur] += sz[u];
        
        for(int i = 0; i <= min(k, sz[cur]); i++){
            for(int j = 0; j <= min(i, sz[u]); j++){
                temp[i] = max(temp[i], dp[cur][i-j] + dp[u][j] + w*(k-j)*j + w*(sz[u]-j)*(n - sz[u] - (k-j)));
            }
        }
        for(int i = 0; i <= min(k, sz[cur]); i++){
            dp[cur][i] = max(dp[cur][i], temp[i]);
            temp[i] = dp[0][0];
        }
    }
}

int main(){
    memset(dp, -0x3f, sizeof dp);
    
    scan(n, k);
    
    for(int i = 0,a,b,c; i < n-1; i++){
        scan(a, b, c);
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    
    if(k > n/2)
        k = n-k;
    
    dfs(1, 0);
    
    print(dp[1][k]);
    
    return 0;
}