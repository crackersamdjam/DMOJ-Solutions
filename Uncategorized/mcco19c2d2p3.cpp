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
const int MM = 1e6+1;

int N, a[MM], nx[MM], dfn[MM], path[MM], ptr, t, low[MM], id[MM], sz[MM];
ll val[2][MM], dp[2][MM], ans;
bool done[MM], ins[MM], cycle[MM];
vector<int> adj[MM];

void dfs(int cur){
    val[1][cur] = a[cur];
    for(int u: adj[cur]){
        if(cycle[u])
            continue;
        dfs(u);
        val[0][cur] += max(val[0][u], val[1][u]);
        val[1][cur] += val[0][u];
    }
}

void go(int cur){
    
    ins[cur] = 1;
    path[++ptr] = cur;
    dfn[cur] = low[cur] = ++t;
    
    for(int u: adj[cur]){
        if(!dfn[u]){
            go(u);
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
            cycle[u] = 1;
            id[u] = cur;
            sz[cur]++;
        }
    }
}

int main(){
    
    scan(N);
    
    for(int i = 1; i <= N; i++){
        scan(a[i], nx[i]);
        adj[nx[i]].push_back(i);
    }
    
    for(int i = 1; i <= N; i++){
        if(!dfn[i])
            go(i);
    }
    
    for(int i = 1; i <= N; i++){
        cycle[i] = sz[id[i]] > 1;
    }
    
    for(int i = 1; i <= N; i++){
        if(cycle[i])
            dfs(i);
    }
    
    for(int i = 1; i <= N; i++){
        if(cycle[i] && !done[i] && id[i] != i){
            
            int cur = i;
            ll best = 0;
            dp[0][i] = val[0][i];
            dp[1][i] = val[1][i];
            
            while(nx[cur] != i){
                done[cur] = 1;
                int n = nx[cur];
                dp[1][n] = dp[0][cur] + val[1][n];
                dp[0][n] = max(dp[0][cur], dp[1][cur]) + val[0][n];
                cur = n;
            }
            done[cur] = 1;
            best = dp[0][cur];
            
            cur = i;
            dp[1][i] = 0;
            while(nx[cur] != i){
                int n = nx[cur];
                dp[1][n] = dp[0][cur] + val[1][n];
                dp[0][n] = max(dp[0][cur], dp[1][cur]) + val[0][n];
                cur = n;
            }
            
            best = max(best, max(dp[0][cur], dp[1][cur]));
            
            ans += best;
        }
    }
    
    print(ans);
    
    return 0;
}
/*
 * subtrees
 * going into connected components
 *
 * dp[u][2]
 *
 * for each tree, push ans into root
 *
 * pick up start point, try choose or not
 * (before go(u, 1), set start node dp[u][0] to -inf so not counted twice)
 *
 *
 * or choose one point on cycle, reverse edges to dp
 * similar to last
 *
 */
/*

5
2 2
1 3
1 4
1 1
10 1

 */