#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 5e5+2, mod = 1e9+7;

int N, M, v[MM], dfn[MM], low[MM], path[MM], t, ptr, id[MM];
int dp[2][MM], cnt[2][MM];
bool ins[MM];
vector<int> adj[MM];
set<int> adjr[MM];

void dfs(int cur){
    
    ins[cur] = 1;
    path[++ptr] = cur;
    dfn[cur] = low[cur] = ++t;
    
    for(int u: adj[cur]){
        if(!dfn[u]){
            dfs(u);
            low[cur] = min(low[cur], low[u]);
        }
        else if(ins[u])
            low[cur] = min(low[cur], dfn[u]);
    }
    
    if(dfn[cur] == low[cur]){
        int u = -1;
        
        while(u ^ cur){
            u = path[ptr--];
            ins[u] = 0;
            id[u] = cur;
            if(u ^ cur)
                v[cur] += v[u];
        }
    }
}

void combine(int &a, int &b, int c, int d){
    if(d <= 0)
        return;
    if(c > a)
        a = c, b = d;
    else if(c == a)
        b = (b+d)%mod;
}

void go(int cur){
    if(~dp[0][cur])
        return;
    
    dp[0][cur] = 0;
    
    for(int u: adjr[cur]){
        go(u);
        combine(dp[1][cur], cnt[1][cur], (v[cur] + dp[0][u])%mod, cnt[0][u]);
        //combine(dp[1][cur], cnt[1][cur], dp[0][u], cnt[0][u]);
        combine(dp[0][cur], cnt[0][cur], dp[1][u], cnt[1][u]);
        combine(dp[0][cur], cnt[0][cur], dp[0][u], cnt[0][u]);
    }
}

int main(){
    
    memset(dp, -1, sizeof dp);
    
    scan(N, M);
    
    for(int i = 1; i <= N; i++)
        scan(v[i]);
    
    for(int i = 0,a,b; i < M; i++){
        scan(a, b);
        adj[a].push_back(b);
    }
    
    dfs(1);
    
    for(int i = 1; i <= N; i++){
        for(int u: adj[i]){
            if(id[u] ^ id[i]){
                //if(adjr[id[i]].count(id[u]))
                  //  abort();
                adjr[id[i]].insert(id[u]);
            }
        }
    }
    
    cnt[0][id[N]] = cnt[1][id[N]] = 1;
    dp[0][id[N]] = 0;
    dp[1][id[N]] = v[id[N]];
    
    go(1);
    
    int a1 = dp[0][1], a2 = cnt[0][1];
    combine(a1, a2, dp[1][1], cnt[1][1]);
    
    print(a1, a2);
    
    return 0;
}