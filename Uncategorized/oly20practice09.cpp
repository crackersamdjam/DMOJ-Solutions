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
const int MM = 1e5+1;

int n, m[3], id[MM];
ll dp[3][MM];
ll fpow(ll fpow_b, ll fpow_exp, ll fpow_mod){if(fpow_exp == 0) return 1;ll t = fpow(fpow_b,fpow_exp/2,fpow_mod);if(fpow_exp&1) return t*t%fpow_mod*fpow_b%fpow_mod;return t*t%fpow_mod;}
ll mod = 1e6;

int main(){
    scan(n);
    for(int i = 0; i < 3; i++)
        scan(m[i]);
    for(int i = 0,a; i < 3; i++){
        while(m[i]--){
            scan(a);
            id[a] = i;
        }
    }
    
    memset(dp, 0x3f, sizeof dp);
    dp[0][1] = dp[1][1] = dp[2][1] = 1;
    dp[id[1]][1] = 0;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(k == id[i] or k == j) continue;
                dp[j][i] = min(dp[j][i], (((j != id[i]) + dp[k][i-1] + fpow(2, i-1, mod)-1) % mod + mod) % mod);
            }
        }
        dp[id[i]][i] = dp[id[i]][i-1];
    }
    pair<ll,int> ans = {1e9, -1};
    for(int i = 0; i < 3; i++)
        ans = min(ans, {dp[i][n], i});
    //print(ans.second+1);
    //print(ans.first);
    print(id[n]+1);
    print(dp[id[n]][n]);
    //assert(ans.first == dp[id[n]][n]);
    //for(int i = 1; i <= n; i++)
      //  print(dp[0][i], dp[1][i], dp[2][i]);
    
    return 0;
}