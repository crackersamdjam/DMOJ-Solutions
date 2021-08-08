#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
const int MM = 1e6+5;
const ll mmod = 1e9+7;

template<class T> T gcd(T _a, T _b){return _b == 0 ? _a : gcd(_b, _a%_b);}
template<class T, class U> T fpow(T _base, U _pow, T _mod){_base %= _mod; T _x = 1; for(; _pow > 0; _pow >>= 1){ if(_pow&1) _x = _x*_base%_mod; _base = _base*_base%_mod;} return _x;}
template<class T> T mulmod(T _a, T _b, T _mod){ return _a%_mod*(_b%_mod)%_mod;}
template<class T> T divmod(T _a, T _b, T _mod){return _a*fpow(_b, _mod-2, _mod)%_mod;}

int n; ll p;
ll cnt[MM];
ll val[MM], f[MM], inv[MM];
int psa[MM];

ll C(int a, int b){
	ll ret = f[a]*inv[b]%p*inv[a-b]%p;
	int k = psa[a] - psa[b] - psa[a-b];
	assert(k >= 0);
	if(k) ret = 0;
	return ret;
}

template<class T> pair<vector<T>, vector<T>> linear_sieve(T N){
	vector<T> low(N+1, 0);
	vector<T> primes;
	for(T i = 2; i <= N; i++){
		if(!low[i])
			low[i] = i, primes.emplace_back(i);
		for(T j = 0; j < (T)size(primes) and primes[j] <= low[i] and i*primes[j] <= N; j++)
			low[i*primes[j]] = primes[j];
	}
	return {move(low), move(primes)};
}

int main(){
	cin>>n>>p;

	f[0] = inv[0] = 1;
	for(int i = 1; i <= n; i++){
		val[i] = i;
		psa[i] = psa[i-1];
		while(val[i] % p == 0){
			val[i] /= p;
			psa[i]++;
		}
		f[i] = f[i-1]*val[i]%p;
		inv[i] = divmod(1LL, f[i], p);
	}

	auto low = linear_sieve(MM).first;

	for(int i = 0; i < n; i++){
		ll a;
		cin>>a;
		ll m = C(n-1, i);
		while(a > 1){
			auto b = low[a];
			cnt[b] += m;
			cnt[b] %= p;
			a /= b;
		}
	}
	ll ans = 1;
	for(ll i = 2; i < MM; i++){
		ans = ans*fpow(i, cnt[i], mmod)%mmod;
	}
	cout<<ans<<'\n';
}