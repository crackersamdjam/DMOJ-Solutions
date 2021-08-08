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
const int MM = 1005;
const ll mod = 1e9+7;

int n;
ll l[MM], r[MM], dp[MM][MM], at[MM], inv[MM];
map<ll, int> mp;

ll gcd(ll gcd_a, ll gcd_b){return gcd_b == 0 ? gcd_a : gcd(gcd_b, gcd_a % gcd_b);}
ll fpow(ll fpow_b, ll fpow_exp, ll fpow_mod){if(fpow_exp == 0) return 1;ll t = fpow(fpow_b,fpow_exp/2,fpow_mod);if(fpow_exp&1) return t*t%fpow_mod*fpow_b%fpow_mod;return t*t%fpow_mod;}
ll divmod(ll divmod_i, ll divmod_j, ll divmod_mod){divmod_i%=divmod_mod,divmod_j%=divmod_mod;return divmod_i*fpow(divmod_j,divmod_mod-2,divmod_mod)%divmod_mod;}

int main(){
    scan(n);
    for(int i = 1; i <= n; i++){
        scan(l[i], r[i]);
        mp[l[i]-1] = mp[r[i]] = 0;
    }
    mp[0] = 0;
    int x = 0;
    for(auto &i: mp){
        i.second = x;
        at[x] = i.first;
        x++;
    }
    assert(x < MM);
    inv[0] = 1;
    for(int i = 1; i < MM; i++)
        inv[i] = fpow(i, mod-2, mod);
    
    for(int j = 0; j <= x; j++)
        dp[0][j] = 1;
    
    for(int i = 1; i <= n; i++){
        dp[i][0] = 1;
        l[i] = mp[l[i]-1], r[i] = mp[r[i]];
        
        for(int j = l[i]+1; j <= r[i]; j++){
            ll val = at[j]-at[j-1];
            dp[i][j] = (dp[i][j] + dp[i-1][j-1]*val) % mod;
    
            ll pre = val-1, d = 1;
            for(int ii = i-1; ii > 0; ii--){
                if(j <= l[ii] or j > r[ii])
                    continue; //does not work
                
                //val, -1 is first fixed, d is how many extra, because these can choose to not be used
                pre = pre*(val-1+d)%mod *inv[d+1]%mod;
                d++;
                if(!pre) break;
                
                dp[i][j] = (dp[i][j] + dp[ii-1][j-1]*pre)%mod;
            }
        }
        for(int j = 1; j < x; j++){
            dp[i][j] = (dp[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] +mod)%mod;
        }
    }
    print((dp[n][x-1]-1+mod)%mod);
    
    return 0;
}
/*

3
1 2
1 2
1 2
 
9
 
 */