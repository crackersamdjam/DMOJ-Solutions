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
const int MM = 3002, mod = 1e9+7;

int n, dp[MM][MM];
char str[MM];

int main(){
    
    scan(n);
    
    for(int i = 2; i <= n; i++)
        str[i] = gc;
    
    dp[1][1] = 1;
    
    for(int i = 2; i <= n; i++){
        if(str[i] == '>'){
            //each j, sum of all dp[i-1][j+1:]
            for(int j = i-1; j > 0; j--){
                dp[i][j] = (dp[i-1][j] + dp[i][j+1])%mod;
            }
        }
        else{
            //'<' each j, sum of all dp[i-1][:j-1]
            for(int j = 1; j <= i; j++){
                dp[i][j] = (dp[i-1][j-1] + dp[i][j-1])%mod;
            }
        }
    }
    
    ll ans = 0;
    
    for(int i = 1; i <= n; i++){
        ans += dp[n][i];
        ans %= mod;
    }
    
    print(ans);
    
    /*
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%lld ", dp[i][j]);
        }
        pc(10);
    }
    */
    return 0;
}