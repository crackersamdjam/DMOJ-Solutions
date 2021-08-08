#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

void init(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
    #endif
}
const int MM = 1e7+1;
int n;
long long suf, dp, inv[MM];
constexpr long long mod = 1e9+7;

int main(){
    init();
    scan(n);
    inv[0] = inv[1] = 1; 
    for (int i = 2; i <= n; i++)  
        inv[i] = inv[mod%i]*(mod-mod/i)%mod;
    for(int i = n-1; i; i--){
        dp = (suf+1)*inv[n-i] + 1;
        suf = (suf + dp)%mod;
    }
    print(dp%mod);
    
    return 0;
}
// dp[i] = (dp[i] + suf)/(n-i+1) + 1
// dp[i]*(n-i+1) = dp[i] + suf + n-i+1
// dp[i]*(n-i) = suf + n-i+1
// dp[i] = (suf+n-i+1)/(n-i)
// dp[i] = (suf+1)/(n-i) + 1