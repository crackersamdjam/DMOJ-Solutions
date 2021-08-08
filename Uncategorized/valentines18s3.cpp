#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 101, mod = 1e9+7;

int dp[MM][MM][MM][2], ans;

//i, last #, k in-row, reached

int n, l;

int main(){
    
    scan(n, l);
    
    dp[0][0][0][0] = 1;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            for(int k = 1; k <= l; k++){
                for(int p = 0; p < j; p++){
                    dp[i][j][k][0] = (dp[i][j][k][0] + dp[i-1][p][k-1][0]) % mod;
                    dp[i][j][k][1] = (dp[i][j][k][1] + dp[i-1][p][k-1][1]) % mod;
                }
                if(k == l){
                    dp[i][j][k][1] = (dp[i][j][k][1] + dp[i][j][k][0]) % mod;
                    dp[i][j][k][0] = 0;
                }
            }
            for(int p = j; p < i; p++){
                for(int pk = 1; pk <= l; pk++){
                    dp[i][j][1][0] = (dp[i][j][1][0] + dp[i-1][p][pk][0]) % mod;
                    dp[i][j][1][1] = (dp[i][j][1][1] + dp[i-1][p][pk][1]) % mod;
                }
            }
        }
    }
    
    for(int j = 1; j <= n; j++)
        for(int k = 1; k <= n; k++)
            ans = (ans + dp[n][j][k][1]) % mod;
    
    print(ans);
    
    return 0;
}