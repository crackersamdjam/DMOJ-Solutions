#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
const int MM = 3e5+1;

int N, M, a[MM], dp[MM];
//cost to remove all of i
vector<int> adj[MM];
bool vis[MM];

int dfs(int cur, int pre){
    
    if(vis[cur])
        return dp[cur];
    vis[cur] = 1;
    
    for(int u: adj[cur]){
        if(u == pre) continue;
        dp[cur] = min(dp[cur], dfs(u, cur));
    }
    
    if(adj[cur].empty())
        dp[cur] = 0;
    
    return (dp[cur] += a[cur]);
}

int main(){
    
    memset(dp, 0x7f, sizeof dp);
    
    scan(N, M);
    for(int i = 0,a,k; i < M; i++){
        scan(a, k);
        for(int j = 0,b; j < k; j++){
            scan(b);
            adj[a].push_back(b);
        }
    }
    
    for(int i = 1; i <= N; i++)
        scan(a[i]);
    
    int ans = dfs(1, -1);
    
    print(ans);
    
    return 0;
}