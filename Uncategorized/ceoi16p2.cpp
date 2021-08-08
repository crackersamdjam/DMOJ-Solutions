#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 2002;

int n, f, s;
ll dp[MM][MM], mod = 1e9+7;

int main(){
    
    scan(n, f, s);
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i; j++){
            if(i == f || i == s)
                dp[i][j] = (dp[i-1][j] + dp[i-1][j+1]*(j+1))%mod;
            else
                dp[i][j] = ((j>0)*dp[i-1][j-1] + dp[i-1][j+1] * ((j+1)*(j)%mod + (i>f)*(j+1) + (i>s)*(j+1))  ) % mod;
        }
    }
    // last dp goes from 0 groups to -1
    print(dp[n-1][0]);
    
    return 0;
}