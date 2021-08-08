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
using pii = pair<ll, int>;
const int MM = 1e4+2;

int n, x[MM], y[MM];
ll m, px[MM], py[MM], dp[MM][101];
//x is buy, y is sell


int main(){
    
    memset(dp, -0x3f, sizeof dp);
    dp[0][0] = 0;
    
    scan(n, m);
    for(int i = 1; i <= n; i++){
        scan(x[i], y[i], px[i], py[i]);
        for(int j = 0; j <= 100; j++){
            for(int k = 0; k <= y[i] and j+k <= 100; k++){
                //sell k
                dp[i][j] = max(dp[i][j], dp[i-1][j+k] - (j+k)*m + py[i]*k);
            }
        }
        for(int j = 0; j <= 100; j++)
            dp[i-1][j] = dp[i][j];
        for(int j = 0; j <= 100; j++){
            //buy k
            for(int k = 0; k <= x[i] and j-k >= 0; k++){
                dp[i][j] = max(dp[i][j], dp[i-1][j-k] - px[i]*k);
            }
        }
    }
    
    print(*max_element(dp[n], dp[n]+101));
    
    return 0;
}