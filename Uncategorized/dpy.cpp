#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MM = 3002, MN = 2e5+2;
#define x first
#define y second
int h, w, n;
pair<int, int> a[MM];
ll dp[MM], fac[MN], inv[MN], mod = 1e9+7;

ll gcd(ll gcd_a, ll gcd_b){return gcd_b == 0 ? gcd_a : gcd(gcd_b, gcd_a % gcd_b);}
ll fpow(ll fpow_b, ll fpow_exp, ll fpow_mod){if(fpow_exp == 0) return 1;ll t = fpow(fpow_b,fpow_exp/2,fpow_mod);if(fpow_exp&1) return t*t%fpow_mod*fpow_b%fpow_mod;return t*t%fpow_mod;}
ll divmod(ll divmod_i, ll divmod_j, ll divmod_mod){divmod_i%=divmod_mod,divmod_j%=divmod_mod;return divmod_i*fpow(divmod_j,divmod_mod-2,divmod_mod)%divmod_mod;}

ll val(int i, int j){
    if(i < 0 or j < 0)
        return 0;
    return fac[i+j]*inv[j] % mod * inv[i] % mod;
}

int main(){
    scanf("%d %d %d", &h, &w, &n);
    for(int i = 1; i <= n; i++)
        scanf("%d %d", &a[i].first, &a[i].second);
    a[0] = {1, 1};
    a[++n] = {h, w};
    sort(a, a+n+1);
    
    fac[0] = inv[0] = 1;
    for(int i = 1; i < MN; i++){
        fac[i] = fac[i-1]*i % mod;
        inv[i] = fpow(fac[i], mod-2, mod);
    }
    
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        dp[i] = val(a[i].x-1, a[i].y-1);
        for(int j = 1; j < i; j++)
            dp[i] = (dp[i] - dp[j]*val(a[i].x-a[j].x, a[i].y-a[j].y) % mod) % mod;
        if(dp[i] < 0)
            dp[i] += mod;
    }
    
    printf("%d\n", dp[n]);
    
    return 0;
}