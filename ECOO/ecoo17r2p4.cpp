#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 10001, mod = 1e9+7;

int tc = 10, n, dp[2][MM];

int main(){
    
    while(tc--){
        scan(n);
    
        dp[1][1] = 1;
        
        int cur = 1, pre = 0;
        for(int i = 2; i <= n; i++){
            swap(cur, pre);
            if(cur == 1){
                for(int j = i-1; j > 0; j--)
                    dp[cur][j] = (dp[pre][j] + dp[cur][j+1])%mod;
            }
            else{
                for(int j = 1; j <= i; j++)
                    dp[cur][j] = (dp[pre][j-1] + dp[cur][j-1])%mod;
            }
        }
    
        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans += dp[cur][i];
            ans %= mod;
            dp[cur][i] = dp[pre][i] = 0;
        }
        
        print(ans);
    }
    
    return 0;
}