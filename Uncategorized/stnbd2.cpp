#include <bits/stdc++.h>
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
const int MM = 1e5+1, mod = 1e9+7;
int N, M, dp[MM], num[MM], ans;
vector<int> adj[MM];
bool in[MM];
int dfs(int cur){
    if(adj[cur].empty()){
        num[cur] = 1;
        return 0;
    }
    if(dp[cur])
        return dp[cur];
    for(int &u: adj[cur]){
        dp[cur] = (dp[cur] + dfs(u)) % mod;
        dp[cur] = (dp[cur] + num[u]) % mod;
        num[cur] = (num[cur] + num[u]) % mod;
    }
    return dp[cur];
}
int main(){
    sc(N); sc(M);
    for(int i = 0,a,b; i < M; i++){
        sc(a); sc(b);
        adj[a].push_back(b);
        in[b] = 1;
    }
    for(int i = 1; i <= N; i++)
        if(!in[i])
            ans = (ans + dfs(i)) % mod;
    printf("%d\n", ans);
    return 0;
}