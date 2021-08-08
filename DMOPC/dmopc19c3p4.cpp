#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 3e5+5;
const ll mod = 1e9+7;

int n;
ll dp[MM][2], ans;
vector<int> adj[MM];
char a[MM];

void dfs(int cur, int pre){
    int v = a[cur];
    dp[cur][0] = dp[cur][1] = 1;
    ll add2 = 0;
    for(int u: adj[cur]){
        if(u == pre)
            continue;
        dfs(u, cur);
        dp[cur][v] = dp[cur][v] * (dp[u][v] + 1) % mod;
        dp[cur][!v] = dp[cur][!v] * (dp[u][!v] + 1) % mod;
        add2 = (add2 - dp[u][!v]) % mod;
    }
    //subtract i because can not only take one path
    dp[cur][!v]--;
    dp[cur][!v] %= mod;
    
    //print(cur, dp[cur][!v] + add2);
    
    ans = (ans + dp[cur][v] + dp[cur][!v] + add2) % mod;
}

int main(){
    
    scanf("%d %s", &n, a+1);
    
    for(int i = 1; i <= n; i++){
        if(a[i] == 'R')
            a[i] = 0;
        else
            a[i] = 1;
    }
    
    for(int i = 0,u,v; i < n-1; i++){
        scan(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, 0);
    
    ans = (ans % mod + mod) % mod;
    print(ans);
    
    //for(int i = 1; i <= n; i++)
      //  print(dp[i][0], dp[i][1]);
    
    return 0;
}
/*
8
RBRRBRBB
1 2
1 3
3 4
1 5
5 6
5 7
5 8

 */