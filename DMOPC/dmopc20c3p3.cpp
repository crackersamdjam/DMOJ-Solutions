#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const ll mod = 1e9+7;

template<class T> T gcd(T _a, T _b){return _b == 0 ? _a : gcd(_b, _a%_b);}
template<class T, class U> T fpow(T _base, U _pow, T _mod){_base %= _mod; T _x = 1; for(; _pow > 0; _pow >>= 1){ if(_pow&1) _x = _x*_base%_mod; _base = _base*_base%_mod;} return _x;}
template<class T> T divmod(T _a, T _b, T _mod){return _a*fpow(_b, _mod-2, _mod)%_mod;}

int t;
ll n, m, k, b;

int main(){
	cin>>t;
	while(t--){
		cin>>n>>m>>k>>b;
		//if all same, then x*k + x*2 = m
		//x(k+2) = m
		ll ans = -1;

		//try 3
		if(n%3 == 0 and k == 1){
			//all are m
			ll r = b*b%mod*b%mod;
			ll a = m%mod *b%mod*b%mod;
			ll rn = fpow(r, n/3, mod);
			ll top = a*(1-rn+mod)%mod;
			ll bot = (1-r+mod)%mod;
			ans = divmod(top, bot, mod);
			goto out;
		}
		//try on/off pattern
		if(n%2 == 0 and m%2 == 0 and k == 2){
			// xk + 2y = m = yk+2x
			//if k == 2
			//2(x+y)
			ll r = b*b%mod;
			// ll a = b*b%mod;
			ll a = m/2%mod *b%mod;
			ll rn = fpow(r, n/2, mod);
			ll top = a*(1-rn+mod)%mod;
			ll bot = (1-r+mod)%mod;
			ans = divmod(top, bot, mod);

			goto out;
		}

		if(m % (k+2) == 0){
			//everyone is x
			ll r = b%mod;
			// ll a = b*b%mod;
			ll a = m/(k+2)%mod;
			ll rn = fpow(r, n, mod);
			ll top = a*(1-rn+mod)%mod;
			ll bot = (1-r+mod)%mod;
			ans = divmod(top, bot, mod);
			goto out;
		}

		out:;
		#ifdef STRESS
		// if(ans != -1) ans = 0;
		#endif
		cout<<ans<<'\n';
	}
}
/*
geo series

*/