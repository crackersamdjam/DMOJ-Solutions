#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e5+1;

int N, K, dp[MM][21], dp2[MM][21], v[MM];
vector<int> adj[MM];

void dfs(int cur, int pre){
    
    dp[cur][0] = v[cur];
    
    for(int u: adj[cur]){
        if(u == pre)
            continue;
        
        dfs(u, cur);
        for(int i = 1; i <= K; i++)
            dp[cur][i] += dp[u][i-1];
    }
}

void dfs2(int cur, int pre){
    dp2[cur][0] = 0;
    dp2[cur][1] = dp[pre][0];
    for(int i = 2; i <= K; i++){
        if(pre)
            dp2[cur][i] = dp[pre][i-1] - dp[cur][i-2] + dp2[pre][i-1];
    }
    for(int u: adj[cur]){
        if(u == pre)
            continue;
        dfs2(u, cur);
    }
}

int main(){
    
    scan(N, K);
    
    for(int i = 0,a,b; i < N-1; i++){
        scan(a, b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i = 1; i <= N; i++)
        scan(v[i]);
    
    dfs(1, 0);
    
    dfs2(1, 0);
    
    for(int i = 1; i <= N; i++){
        int sum = 0;
        for(int j = 0; j <= K; j++)
            sum += dp[i][j] + dp2[i][j];
        print(sum);
    }
    
    return 0;
}