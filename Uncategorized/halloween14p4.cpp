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
const int MM = 1e5+1;

int n, c[MM], st, ed;
ll dp[MM][3], ans, inf = 1e12;
bool vis[MM];
set<int> adj[MM];

void go(int cur, int pre){
    
    dp[cur][1] = c[cur];
    dp[cur][0] = 0, dp[cur][2] = 0;
    ll mind = inf;
    
    for(int u: adj[cur]){
        if(u == st)
            mind = 0;
        if(u == pre || u == st || (cur == st && u == ed))
            continue;
        go(u, cur);
        dp[cur][1] += min(dp[u][1], dp[u][0]);
        if(u == st)
            dp[cur][0] += min(dp[u][1], dp[u][0]);
        else
            dp[cur][0] += min(dp[u][1], dp[u][2]);
        
        if(dp[u][1] <= dp[u][2]){
            mind = 0;
            dp[cur][2] += dp[u][1];
        }
        else{
            mind = min(mind, dp[u][1] - dp[u][2]);
            dp[cur][2] += dp[u][2];
        }
    }
    
    dp[cur][2] += mind;
    
    dp[cur][0] = min(dp[cur][0], dp[cur][2]);
}

void go2(int cur, int pre){
    
    dp[cur][1] = c[cur];
    dp[cur][0] = 0, dp[cur][2] = 0;
    ll mind = inf;
    
    for(int u: adj[cur]){
        if(u == pre || u == st || (cur == st && u == ed))
            continue;
        go2(u, cur);
        dp[cur][1] += min(dp[u][1], dp[u][0]);
        dp[cur][0] += min(dp[u][1], dp[u][2]);
    
        if(dp[u][1] <= dp[u][2]){
            mind = 0;
            dp[cur][2] += dp[u][1];
        }
        else{
            mind = min(mind, dp[u][1] - dp[u][2]);
            dp[cur][2] += dp[u][2];
        }
    }
    
    dp[cur][2] += mind;
    
    dp[cur][0] = min(dp[cur][0], dp[cur][2]);
}

void dfs(int cur, int pre){
    vis[cur] = 1;
    for(int u: adj[cur]){
        if(u == pre)
            continue;
        if(vis[u])
            st = u, ed = cur;
        else
            dfs(u, cur);
    }
}

int main(){
    
    scan(n);
    
    for(int i = 1; i <= n; i++)
        scan(c[i]);
    
    for(int i = 1,a; i <= n; i++){
        scan(a);
        adj[a].insert(i);
        adj[i].insert(a);
    }
    
    for(int i = 1; i <= n; i++){
        if(vis[i])
            continue;
        
        st = ed = 0;
        dfs(i, 0);
        
        if(st){
            go(st, 0);
            ll v = dp[st][1];
            
            go2(st, 0);
            v = min(v, dp[st][2]);
            
            swap(st, ed);
            go(st, 0);
            v = min(v, dp[st][1]);
            
            ans += v;
        }
        else{
            go(i, 0);
            ans += min(dp[i][1], dp[i][2]);
        }
    }
    
    print(ans);
    
    
    return 0;
}