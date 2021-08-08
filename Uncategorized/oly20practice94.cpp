#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int MM = 12e5+5;
ll gcd(ll gcd_a, ll gcd_b){return gcd_b == 0 ? gcd_a : gcd(gcd_b, gcd_a % gcd_b);}
ll fpow(ll fpow_b, ll fpow_exp, ll fpow_mod){if(fpow_exp == 0) return 1;ll t = fpow(fpow_b,fpow_exp/2,fpow_mod);if(fpow_exp&1) return t*t%fpow_mod*fpow_b%fpow_mod;return t*t%fpow_mod;}
ll divmod(ll divmod_i, ll divmod_j, ll divmod_mod){divmod_i%=divmod_mod,divmod_j%=divmod_mod;return divmod_i*fpow(divmod_j,divmod_mod-2,divmod_mod)%divmod_mod;}

ll f[MM], inv[MM];

ll C(int n, int k){
	if(k < 0)
		return 0;
	return f[n]*inv[k]%mod*inv[n-k]%mod;
}

int tc, n, a[MM], suf[MM];

ll val(int i, int j){
	if(i < 0)
		return 0;
	ll ret = C(i+j, i) - C(i+j, i-1);
	if(ret < 0)
		ret += mod;
	return ret;
}

int main(){
	f[0] = inv[0] = 1;
	for(int i = 1; i < MM; i++)
		f[i] = f[i-1]*i%mod;
	
	inv[MM-1] = divmod(1, f[MM-1], mod);
	for(int i = MM-2; i; i--)
		inv[i] = inv[i+1]*(i+1)%mod;

	scan(tc);
	while(tc--){
		scan(n);
		ll ans = 0;
		int pre = 0;
		for(int i = 1; i <= n; i++)
			scan(a[i]);
		suf[n+1] = 1e9;
		for(int i = n; i; i--)
			suf[i] = min(suf[i+1], a[i]);

		for(int i = 1; i <= n; i++){
			pre = max(pre, a[i]);
			ll add = val(n-(pre+1), n-i+1);
			ans += add;
			if(ans >= mod)
				ans -= mod;
			if(a[i] < pre and suf[i+1] < a[i])
				break;
		}
		print(ans);
	}
}