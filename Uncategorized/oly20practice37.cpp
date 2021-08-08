#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

typedef long long ll ;
constexpr int MM = 3001;
constexpr ll mod = 1e9+7;

int n, m;
ll dp[MM][MM];

int main(){
    scan(n, m);
    
    dp[0][0] = 1;
    for(int i = 0; i < MM; i++)
        dp[i][0] = dp[0][i] = 1;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            // fix current outermost i, but not j
            if(i) dp[i][j] += dp[i-1][j];
            
            if(i and j) dp[i][j] += (4*j*dp[i-1][j-1])%mod;
            
            if(i and j > 1){
                dp[i][j] += ((j*(j-1)/2 % mod) * dp[i-1][j-2])%mod;
            }
            if(j and i > 1){
                dp[i][j] += (((i-1)*j % mod) * dp[i-2][j-1])%mod;
            }
            
            dp[i][j] %= mod;
            if(dp[i][m] < 0)
                dp[i][m] += mod;
//            printf("%lld ", dp[i][j]);
        }
//        pc(10);
    }
    
    dp[n][m] = (dp[n][m]+mod-1)%mod;
    
    print(dp[n][m]);
    
    
    return 0;
}
/*
2 2
52
 */