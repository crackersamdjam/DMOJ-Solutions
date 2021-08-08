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
const int MM = 1001, mod = 998244353;

int n, K, c[MM], sz[MM];
ll dp[MM][MM][3][3], sum[MM][MM][3][3], ans;
vector<int> adj[MM];

void go(int cur, int p){
    
    dp[cur][1][c[cur]][c[cur]^1] = 1;
    sz[cur] = 1;
    
    for(int u: adj[cur]){
        if(u == p)
            continue;
        
        go(u, cur);
        
        for(int i = 1; i <= sz[cur]; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    
                    for(int ii = 1; ii <= min(n-i, sz[u]); ii++){
                        for(int jj = 0; jj < 3; jj++){
                            for(int kk = 0; kk < 3; kk++){
                                sum[cur][i+ii][min(2, j+jj)][min(2, k+kk)] += dp[cur][i][j][k] * dp[u][ii][jj][kk] % mod;
                                sum[cur][i+ii][min(2, j+jj)][min(2, k+kk)] %= mod;
                            }
                        }
                    }
                    
                }
            }
        }
        sz[cur] += sz[u];
        
        for(int i = 1; i <= sz[cur]; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    dp[cur][i][j][k] += sum[cur][i][j][k];
                    dp[cur][i][j][k] %= mod;
                    sum[cur][i][j][k] = 0;
                }
            }
        }
    }
}

int main(){
    
    scan(n, K);
    
    for(int i = 1; i <= n; i++)
        c[i] = gc == 'R';
    
    for(int i = 0,a,b; i < n-1; i++){
        scan(a, b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    go(1, 0);
    
    for(int i = 1; i <= n; i++){
        ans += dp[i][K][2][2];
        ans %= mod;
    }
    
    print(ans);
    
    return 0;
}