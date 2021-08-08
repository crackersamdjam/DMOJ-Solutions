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
const int MM = 201;
constexpr ll mod = 1e9+7;

int n, w, m;
ll dp[MM][MM][2], all[MM];
vector<pair<int, int>> adj[MM];

bool done[MM], in[MM];

void addmod(ll &a, ll b){ a += b; if(a >= mod) a -= mod;}
void submod(ll &a, ll b){ a -= b; if(a < 0) a += mod;}

//0 human, 1 werewolf
void dfs(int u){
    done[u] = 1;
    for(int i = 0; i <= w; i++)
        dp[u][i][0] = dp[u][i][1] = 0;
    dp[u][0][0] = dp[u][1][1] = 1;
    
    for(auto e: adj[u]){
        int v = e.first;
        dfs(v);
        //human
        for(int i = w; i >= 0; i--){
            ll tmp = dp[u][i][0];
            for(int j = 0; j <= i; j++){
                addmod(dp[u][i][0], (dp[v][j][0] + dp[v][j][1]) * dp[u][i-j][0] % mod);
            }
            submod(dp[u][i][0], tmp);
        }
    
        //werewolf
        for(int i = w; i >= 0; i--){
            ll tmp = dp[u][i][1];
            for(int j = 0; j <= i; j++){
                addmod(dp[u][i][1], (dp[v][j][e.second]) * dp[u][i-j][1] % mod);
                //if defending other, other must be werewolf
            }
            submod(dp[u][i][1], tmp);
        }
    }
}


int main(){
    
    scan(n, w, m);
    
    for(int i = 0,a,b,op; i < m; i++){
        op = gc; scan(a, b);
        adj[a].emplace_back(b, op=='D');
        in[b] = 1;
    }
    
    all[0] = 1;
    for(int u = 1; u <= n; u++){
        if(!in[u]){
            dfs(u);
            for(int i = w; i >= 0; i--){
                ll tmp = all[i];
                for(int j = 0; j <= i; j++)
                    addmod(all[i], (dp[u][j][0] + dp[u][j][1]) * all[i-j] % mod);
                submod(all[i], tmp);
            }
        }
    }
    
    print(all[w]);
    
    return 0;
}