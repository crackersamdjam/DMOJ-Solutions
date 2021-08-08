#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
typedef long long ll;
const int MM = 1e4+1, mod = 1e9;

int N, M, good[MM];
bool in[MM], ok;
ll dp[MM];
vector<int> adj[MM];

ll go(int cur){
    
    if(in[cur])
        ok = 1;
    
    if(ok)
        return 0;
    
    if(~dp[cur])
        return dp[cur];
    
    in[cur] = 1;
    dp[cur] = 0;
    
    for(auto u: adj[cur]){
        if(!good[u])
            continue;
        dp[cur] += go(u);
        if(dp[cur] >= mod){
            dp[cur] %= mod;
            dp[cur] += mod;
        }
    }
    
    in[cur] = 0;
    return dp[cur];
}

bool prune(int cur){
    if(~good[cur])
        return good[cur];
    good[cur] = 0;
    for(auto u: adj[cur]){
        good[cur] |= prune(u);
    }
    return good[cur];
}

int main(){
    
    memset(good, -1, sizeof good);
    memset(dp, -1, sizeof dp);
    
    scan(N, M);
    
    for(int i = 0,a,b; i < M; i++){
        scan(a, b);
        adj[a].push_back(b);
    }
    
    good[2] = dp[2] = 1;
    
    prune(1);
    
    ll ans = go(1);
    
    if(ok)
        return 0*puts("inf");
    
    if(ans >= mod){
        ans %= mod;
        printf("%09lld\n", ans);
    }
    else
        print(ans);
    
}