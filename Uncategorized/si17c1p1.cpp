#include <bits/stdc++.h>
#define MM 21
#define f first
#define s second
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef pair<int,int> pii;
char _;
const int inf = 0x3f3f3f3f;
vector<pii> adj[MM];
vector<int> valid[MM];
int n,m,k, dp[1<<MM], dis[MM];
bool vis[MM];

inline int bit(int x){
    return __builtin_popcount(x);
}
inline int lead(int x){
    return 31 - __builtin_clz(x);
}

inline bool in(int v, int mask){
    return ((1<<v) & mask);
}

priority_queue<pii,vector<pii>,greater<pii>> q;
inline int prim(int mask){
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    
    int st = 0;
    while(!in(st ,mask))
        st++;
    
    dis[st] = 0;
    q.push({0, st});
    
    while(!q.empty()){
        
        int cur = q.top().s; q.pop();
        if(vis[cur]) continue;
        vis[cur] = 1;
        
        for(auto &e: adj[cur]){
            if(in(e.f,mask) && !vis[e.f] && e.s < dis[e.f]){
                dis[e.f] = e.s;
                q.push({e.s, e.f});
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(in(i, mask)){
            if(dis[i] >= inf)
                return inf;
            sum += dis[i];
        }
    }
    return sum;
}
int go(int mask){
    if(dp[mask] != inf)
        return dp[mask];
    int ret = inf;
    for(int nx: valid[lead(mask)]){
        if((mask & nx) == nx){
            ret = min(ret, dp[nx] + go(mask^nx));
        }
    }
    return dp[mask] = min(ret, inf);
}
int main(){
    memset(dp,0x3f,sizeof dp);
    sc(n); sc(m); sc(k);
    if(n%k){
        printf("-1\n");
        return 0;
    }
    for(int i = 0,a,b,c; i < m; i++){
        sc(a); sc(b); sc(c);
        a--, b--;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    for(int i = 1; i < (1<<n); i++){
        if(bit(i) == n/k){
            valid[lead(i)].push_back(i);
            dp[i] = prim(i);
        }
    }
    dp[0] = 0;
    int ans = go((1<<n)-1);
    printf("%d\n", (ans >= inf)? -1: ans);
    return 0;
}
/*
 * check transitions again
 */