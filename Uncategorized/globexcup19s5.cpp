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
constexpr int MM = 301, MN = 3e5+1, mod = 1e9+7;

ll gcd(ll gcd_a, ll gcd_b){return gcd_b == 0 ? gcd_a : gcd(gcd_b, gcd_a % gcd_b);}
ll fpow(ll fpow_b, ll fpow_exp, ll fpow_mod){if(fpow_exp == 0) return 1;ll t = fpow(fpow_b,fpow_exp/2,fpow_mod);if(fpow_exp&1) return t*t%fpow_mod*fpow_b%fpow_mod;return t*t%fpow_mod;}
ll divmod(ll divmod_i, ll divmod_j, ll divmod_mod){divmod_i%=divmod_mod,divmod_j%=divmod_mod;return divmod_i*fpow(divmod_j,divmod_mod-2,divmod_mod)%divmod_mod;}

int n, k, t[MM], id;
ll x[MM], y[MM], z[MM];
ll dp[MM], f[MN], inv[MN], ans = 1;

ll C(int a, int b, int c){
    a = abs(a), b = abs(b), c = abs(c);
    return ((f[a+b+c] * inv[a] % mod) * inv[b] % mod) * inv[c] % mod;
}

ll go(int i){
    if(~dp[i])
        return dp[i];
    dp[i] = C(x[i], y[i], z[i]);
    for(int j = 0; j < n; j++){
        if(j != i and t[j] != id and x[i]*x[j] >= 0 and y[i]*y[j] >= 0 and z[i]*z[j] >= 0
        and abs(x[i]) >= abs(x[j]) and abs(y[i]) >= abs(y[j]) and abs(z[i]) >= abs(z[j])){
            dp[i] -= go(j)*C(x[i]-x[j], y[i]-y[j], z[i]-z[j])%mod;
            if(dp[i] < 0)
                dp[i] += mod;
        }
    }
    return dp[i];
}

int main(){
    
    f[0] = 1;
    inv[0] = 1;
    for(int i = 1; i < MN; i++){
        f[i] = f[i-1]*i%mod;
        inv[i] = fpow(f[i], mod-2, mod);
    }
    
    scan(n, k);
    
    for(int i = 0; i < n; i++)
        scan(x[i], y[i], z[i], t[i]);
    
    for(id = 1; id <= k; id++){
        memset(dp, -1, sizeof dp);
        ll cnt = 0;
        for(int i = 0; i < n; i++){
            if(t[i] == id){
                cnt += go(i);
                if(cnt >= mod)
                    cnt -= mod;
            }
        }
        ans = ans*cnt % mod;
    }
    
    print(ans);
    
    return 0;
}