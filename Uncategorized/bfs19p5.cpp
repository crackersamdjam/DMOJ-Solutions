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
const int MM = 1e5+1, MN = 25;

int n, q, par[MM], dep[MM], lca[MN][MM];
ll dp[MM], dp2[MM], cnt[MM];
//sum for nodes going up
vector<int> adj[MM];

void dfs(int cur, int pre){
    par[cur] = pre;
    if(cur != 1)
        dep[cur] = dep[pre]+1;
    cnt[cur] = 1;
    for(int u: adj[cur]){
        if(u == pre)
            continue;
        dfs(u, cur);
        dp[cur] += dp[u]+cnt[u]; //each one adds
        cnt[cur] += cnt[u];
        lca[0][u] = cur;
    }
}

void dfs2(int cur, int pre){
    //coming above from parent but not current
    if(cur != 1){
        dp2[cur] = dp2[pre] + dp[pre] - (dp[cur]+cnt[cur]) + (n - cnt[cur]);
    }
    for(int u: adj[cur]){
        if(u == pre)
            continue;
        dfs2(u, cur);
    }
}

int query(int u, int v){
    if(dep[u] < dep[v])
        swap(u, v);
    //u gets jumped up
    for(int i = MN-1; i >= 0; i--){
        if((lca[i][u] != -1) && (dep[lca[i][u]] >= dep[v]))
            u = lca[i][u];
    }
    //now should be on same level
    if(u == v)
        return u;
    for(int i = MN-1; i >= 0; i--){
        if((lca[i][u] != -1) && (lca[i][v] != -1) && (lca[i][u] != lca[i][v])){
            u = lca[i][u];
            v = lca[i][v];
        }
    }
    return lca[0][u];
    //return direct parent
}

int main(){
    
    memset(lca, -1, sizeof lca);
    
    scan(n, q);
    
    for(int i = 0,a,b; i < n-1; i++){
        scan(a, b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    //so 1 is root
    dfs(1, 0);
    dfs2(1, 0);
    
    for(int i = 1; i < MN; i++){
        for(int j = 1; j <= n; j++){
            if(lca[i-1][j] != -1)
                lca[i][j] = lca[i-1][ lca[i-1][j] ];
        }
    }
    
    
    
    for(int i = 0,a,b; i < q; i++){
        scan(a, b);
        
        /*
        if(par[a] == par[b]){
            puts("0");
            continue;
        }*/
        
        
        int lcan = query(a, b);
        
        ll dis = dep[a]+dep[b] - dep[lcan]*2;
        //print(lcan, dep[lcan]);
        
        ll ans = 0;
        ans -= dp[a]*(n-cnt[a]) + cnt[a]*dp2[a];
        ans -= dp[b]*(n-cnt[b]) + cnt[b]*dp2[b];
        
        //if(a == 3 && b == 6)
          //  print(dp[a]*(n-cnt[a]) + cnt[a]*dp2[a] ,dp[b]*(n-cnt[b]) + cnt[b]*dp2[b]);
        
        ll dpv = dp2[a] - dp[b] - cnt[b]*dis + dp[a] + cnt[a]*dis;
        ans += dp[b]*(n-cnt[b]) + cnt[b]*dpv;
    
        dpv = dp2[b] - dp[a] - cnt[a]*dis + dp[b] + cnt[b]*dis;
        ans += dp[a]*(n-cnt[a]) + cnt[a]*dpv;
        
        //printf("%lld ", ans);
        if(ans > 0)
            puts("1");
        else if(ans < 0)
            puts("-1");
        else
            puts("0");
        
        /*
        if(a == 3 && b == 6){
            print(ans);
        }*/
    }
    /*
    for(int i = 1; i <= n; i++)
        printf("%lld ", dp[i]);
    pc(10);
    for(int i = 1; i <= n; i++)
        printf("%lld ", dp2[i]);
    pc(10);
    for(int i = 1; i <= n; i++)
        printf("%lld ", cnt[i]);
    pc(10);
    */
    return 0;
}
/*
 * node a:
 * dp[b]*(n - cnt[b]) + cnt[b]*((n - cnt[b]) + (dp2[a] + dis*dp[a] ))
 *                            extra one;    sum of dp...
 */